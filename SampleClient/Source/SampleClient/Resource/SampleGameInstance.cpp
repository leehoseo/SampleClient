// Fill out your copyright notice in the Description page of Project Settings.



#include "SampleGameInstance.h"
#include "ClientIocp.h"
#include "ClientActor.h"
#include "Dispatcher.h"
#include "SystemManager.h"

void USampleGameInstance::Init()
{
	UGameInstance::Init();
	ConnectServer();
}

void USampleGameInstance::ConnectServer()
{
	WSADATA w;
	WSAStartup(MAKEWORD(2, 2), &w);
	SystemManager::getInstance()->init(new ClientActor(), new ClientIocp());

	Iocp* iocp = SystemManager::getInstance()->getIcop();
	iocp->init();

	SystemManager::getInstance()->insertAndRunThread();


	//// 요건 쓰래드로 빼 말아
	//while (true)
	//{
	//	iocp->execute();
	//	Dispatcher::getInstance()->execute();
	//}

	WSACleanup();
}