// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
//#include "Base.h"
#include "Tickable.h"
#include "SampleGameInstance.generated.h"

USampleGameInstance* GetSampleGameInstance();

/**
 * 
 */

UCLASS()
class SAMPLECLIENT_API USampleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init();
	virtual void Shutdown();

	void ConnectServer(const FString& name );

	/*const ActorKey& GetSelfPlayerActorKey();
	void SetSelfPlayerActorKey(const ActorKey& ActorKey);*/

	// ���⼭ ���� ������ �������� Tick�� ����Ѵ�.
	bool Tick(float DeltaSeconds);

private:
	//ActorKey SelfPlayerActorKey;

	FDelegateHandle TickDelegateHandle;

	bool IsInit = false;
};