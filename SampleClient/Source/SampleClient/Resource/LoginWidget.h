// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECLIENT_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// UI에 함수 바인딩
	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* LoginButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* EditableTextBox_ID;

	UFUNCTION()
	void OnClickLogin();
};
