// Fill out your copyright notice in the Description page of Project Settings.
#include "SampleGameInstance.h"
#include "ClientIocp.h"
#include "ClientActor.h"
#include "Dispatcher.h"
#include "SystemManager.h"
#include "TrAuth.h"
#include "TrQueueManager.h"
#include "NetworkContents.h"
#include "Kismet/GameplayStatics.h"

USampleGameInstance* SampleGameInstance = nullptr;

USampleGameInstance* GetSampleGameInstance()
{
	return SampleGameInstance;
}

void USampleGameInstance::Init()
{
	WSADATA w;
	WSAStartup(MAKEWORD(2, 2), &w);

	UGameInstance::Init();

	SystemManager::getInstance()->init(new ClientActor(), new ClientIocp());
	SystemManager::getInstance()->insertAndRunThread();
	SampleGameInstance = this;

	// Tickµî·Ï
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &USampleGameInstance::Tick));
}


void USampleGameInstance::Shutdown()
{
	// Unregister ticker delegate
	FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);

	ClientIocp* iocp = static_cast<ClientIocp*>(SystemManager::getInstance()->getIcop());
	iocp->release();

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
	ClientIocp* iocp = static_cast<ClientIocp*>(SystemManager::getInstance()->getIcop());
	if (true == iocp->checkConnect())
	{
		UGameplayStatics::OpenLevel(this, "FirstPersonMap");
		return;
	}

	iocp->init();
	TrNetworkConnectReq req;
	req.set(TCHAR_TO_ANSI(*name));
	iocp->connnectServer(&req);
}

const ActorKey& USampleGameInstance::GetSelfPlayerActorKey()
{
	return SelfPlayerActorKey;
}

void USampleGameInstance::SetSelfPlayerActorKey(const ActorKey& ActorKey)
{
	SelfPlayerActorKey = ActorKey;
}