#include "TrAuthProc.h"
#include "TrAuth.h"
#include "SampleGameInstance.h"
#include "Kismet/GameplayStatics.h"

#pragma optimize ("",off)
MAKE_PROCESS(TrNetworkConnectAck)
{
	//TrNetworkConnectAck* Ack = static_cast<TrNetworkConnectAck*>(tr);

	// 검증
	{
		// 뭐 스트링 그런거 하면 될듯
	}

	// 게임인스턴스에 기본 정보 추가
	//GetSampleGameInstance()->SetSelfPlayerActorKey(Ack->_actorKey);

	// 레벨 접속
	// WorldContextObject 아무거나 넣어도 됨
	// UObject로 GetWorld()를 호출하는것 말고는 없다.
	UGameplayStatics::OpenLevel(GetSampleGameInstance(), "FirstPersonMap");
}

MAKE_PROCESS(TrActorLoginAck)
{
	//TrActorLoginAck* ack = static_cast<TrActorLoginAck*>(tr);

	// 검증
	{
		// 뭐 스트링 그런거 하면 될듯
	}

	// 내가 사용할 액터 생성

	UWorld* World = GetSampleGameInstance()->GetWorld();

	if (nullptr == World)
	{
		// 에러 에러 에러
	}

	//if (GetSampleGameInstance()->GetSelfPlayerActorKey() == ack->_actorKey )
	//{
	//	
	//}
	//else // 다른 플레이어의 액터 생성
	//{

	//}
}
