// Fill out your copyright notice in the Description page of Project Settings.



#include "SampleGameInstance.h"

void USampleGameInstance::Init()
{
	UGameInstance::Init();
	ConnectServer();
}

void USampleGameInstance::ConnectServer()
{
	//WSADATA w;
	//WSAStartup(MAKEWORD(2, 2), &w);

	//SystemManager::getInstance()->init(new ClientActor(), new ClientIocp());
	//SystemManager::getInstance()->insertAndRunThread();

	//Iocp* iocp = SystemManager::getInstance()->getIcop();
	//iocp->init();

	////// 요건 쓰래드로 빼 말아
	////while (true)
	////{
	////	iocp->execute();
	////	Dispatcher::getInstance()->execute();
	////}

	//WSACleanup();
}