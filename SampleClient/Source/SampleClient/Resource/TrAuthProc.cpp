#include "TrAuthProc.h"
#include "TrAuth.h"
#include "SampleGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

#pragma optimize ("",off)
void TrNetworkConnectAckProc::process(Tr* tr)
{
	TrNetworkConnectAck* ack = static_cast<TrNetworkConnectAck*>(tr);

	// ����
	{
		// �� ��Ʈ�� �׷��� �ϸ� �ɵ�
	}

	// Actor ����

	USampleGameInstance* sampleGameInstance = static_cast<USampleGameInstance*>(GEngine->GetWorld()->GetGameInstance());
	sampleGameInstance->SetPlayerActorKey(ack->_actorKey);
}

void TrActorLoginAckProc::process(Tr* tr)
{
	TrActorLoginAck* ack = static_cast<TrActorLoginAck*>(tr);

	// ����
	{
		// �� ��Ʈ�� �׷��� �ϸ� �ɵ�
	}

	// Actor ����
	USampleGameInstance* sampleGameInstance = static_cast<USampleGameInstance*>(GEngine->GetWorld()->GetGameInstance());

	// ���� ����� ���� ����
	if ( sampleGameInstance->GetPlayerActorKey() == ack->_actorKey )
	{

	}
	else // �ٸ� �÷��̾��� ���� ����
	{

	}
}
