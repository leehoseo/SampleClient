// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Base.h"
#include "SampleGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECLIENT_API USampleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init();

	void ConnectServer();

	const Session_ID&	GetSessionId();
	void				SetSessionId(const Session_ID& NewSessionId);

private:
	Session_ID SessionId = undefinedSessionId;
};
