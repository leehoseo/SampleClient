#include "TrAuthProc.h"
#include "TrAuth.h"
#include "SampleGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

#pragma optimize ("",off)
void TrNetworkConnectAckProc::process(Tr* tr)
{
	TrNetworkConnectAck* ack = static_cast<TrNetworkConnectAck*>(tr);

	// 검증
	{
		// 뭐 스트링 그런거 하면 될듯
	}

	// Actor 생성

	USampleGameInstance* sampleGameInstance = static_cast<USampleGameInstance*>(GEngine->GetWorld()->GetGameInstance());
	sampleGameInstance->SetPlayerActorKey(ack->_actorKey);
}

void TrActorLoginAckProc::process(Tr* tr)
{
	TrActorLoginAck* ack = static_cast<TrActorLoginAck*>(tr);

	// 검증
	{
		// 뭐 스트링 그런거 하면 될듯
	}

	// Actor 생성
	USampleGameInstance* sampleGameInstance = static_cast<USampleGameInstance*>(GEngine->GetWorld()->GetGameInstance());

	// 내가 사용할 액터 생성
	if ( sampleGameInstance->GetPlayerActorKey() == ack->_actorKey )
	{

	}
	else // 다른 플레이어의 액터 생성
	{

	}
}
