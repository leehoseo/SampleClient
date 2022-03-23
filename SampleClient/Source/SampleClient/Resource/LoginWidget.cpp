// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "UMG/Public/Components/Button.h"
#include "UMG/Public/Components/EditableTextBox.h"
#include "SampleGameInstance.h"

bool ULoginWidget::Initialize()
{
	const bool IsInit = UUserWidget::Initialize();

	LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnClickLogin);

	return IsInit;
}

void ULoginWidget::OnClickLogin()
{
	//UE_LOG(LogTemp, Warning, TEXT(EditableTextBox_ID->Text.ToString()));
	/*USampleGameInstance* sampleGameInstance = Cast<USampleGameInstance>(GetWorld()->GetGameInstance());
	sampleGameInstance->ConnectServer(EditableTextBox_ID->Text.ToString());*/
}