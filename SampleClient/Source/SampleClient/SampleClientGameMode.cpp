// Copyright Epic Games, Inc. All Rights Reserved.

#include "SampleClientGameMode.h"
#include "SampleClientCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASampleClientGameMode::ASampleClientGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
