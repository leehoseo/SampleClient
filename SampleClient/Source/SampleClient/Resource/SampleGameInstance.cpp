// Fill out your copyright notice in the Description page of Project Settings.



#include "SampleGameInstance.h"
#include "ClientIocp.h"
#include "ClientActor.h"
#include "Dispatcher.h"
#include "SystemManager.h"
#include "TrAuth.h"
void USampleGameInstance::Init()
{
	UGameInstance::Init();

	SystemManager::getInstance()->init(new ClientActor(), new ClientIocp());
	SystemManager::getInstance()->insertAndRunThread();
}

void USampleGameInstance::ConnectServer(const FString& name)
{
	WSADATA w;
	WSAStartup(MAKEWORD(2, 2), &w);

	ClientIocp* iocp = static_cast<ClientIocp*>(SystemManager::getInstance()->getIcop());
	iocp->init();

	TrNetworkConnectReq req;
	req.set(TCHAR_TO_ANSI(*name));
	iocp->connnectServer(&req);

	WSACleanup();
}

const ActorKey& USampleGameInstance::GetPlayerActorKey()
{
	return PlayerActorKey;
}

void USampleGameInstance::SetPlayerActorKey(const ActorKey& ActorKey)
{
	PlayerActorKey = ActorKey;
}
