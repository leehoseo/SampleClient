// Fill out your copyright notice in the Description page of Project Settings.
#include "SampleGameInstance.h"
#include "ClientIocp.h"
#include "ClientActor.h"
#include "Dispatcher.h"
#include "SystemManager.h"
#include "TrAuth.h"
#include "TrQueueManager.h"
#include "ClientNetworkContents.h"
#include "Kismet/GameplayStatics.h"
#include "SendEvent.h"

USampleGameInstance* SampleGameInstance = nullptr;
USampleGameInstance* GetSampleGameInstance()
{
	return SampleGameInstance;
}

void USampleGameInstance::Init()
{
	SampleGameInstance = this;

	UGameInstance::Init();

	if (false == IsInit)
	{
		WSADATA w;
		WSAStartup(MAKEWORD(2, 2), &w);

		SystemManager::getInstance()->init(new ClientActor(), new ClientIocp());
		SystemManager::getInstance()->insertAndRunThread();

		{
			Actor* mainActor = SystemManager::getInstance()->getMainActor();
			ClientNetworkContents* contents = static_cast<ClientNetworkContents*>(mainActor->getContents(ContentsType::eNetwork));

			contents->requestConnectToServer();
		}

		IsInit = true;
	}
	// Tickµî·Ï
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &USampleGameInstance::Tick));
}

void USampleGameInstance::Shutdown()
{
	// Unregister ticker delegate
	FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);

	Actor* mainActor = SystemManager::getInstance()->getMainActor();
	ClientNetworkContents* contents = static_cast<ClientNetworkContents*>(mainActor->getContents(ContentsType::eNetwork));

	contents->requestDisConnectFromServer();
	WSACleanup();

	UGameInstance::Shutdown();
}	

bool USampleGameInstance::Tick(float DeltaSeconds)
{
	Actor* mainActor = SystemManager::getInstance()->getMainActor();
	NetworkContents* contents = static_cast<NetworkContents*>(mainActor->getContents(ContentsType::eNetwork));
	Tr* tr = TrQueueManager::getInstance()->pop(ThreadType::eClient);

	if (nullptr == tr)
	{
		return true;
	}

	contents->recvTr(tr);

	delete tr;
	return true;
}


void USampleGameInstance::ConnectServer(const FString& name)
{
	Actor* mainActor = SystemManager::getInstance()->getMainActor();
	NetworkContents* contents = static_cast<NetworkContents*>(mainActor->getContents(ContentsType::eNetwork));

	TrActorLoginReq* req = new TrActorLoginReq();
	req->set(TCHAR_TO_ANSI(*name));
	contents->sendToServer(req, 0);
}

const ActorKey& USampleGameInstance::GetSelfPlayerActorKey()
{
	return SelfPlayerActorKey;
}

void USampleGameInstance::SetSelfPlayerActorKey(const ActorKey& ActorKey)
{
	SelfPlayerActorKey = ActorKey;
}