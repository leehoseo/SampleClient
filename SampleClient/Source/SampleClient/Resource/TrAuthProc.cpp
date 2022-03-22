#include "TrAuthProc.h"
#include "TrAuth.h"
#include "SampleGameInstance.h"
#include "Kismet/GameplayStatics.h"

#pragma optimize ("",off)
void TrNetworkConnectAckProc::process(Tr* tr)
{
	TrNetworkConnectAck* Ack = static_cast<TrNetworkConnectAck*>(tr);

	// ����
	{
		// �� ��Ʈ�� �׷��� �ϸ� �ɵ�
	}

	// �����ν��Ͻ��� �⺻ ���� �߰�
	GetSampleGameInstance()->SetSelfPlayerActorKey(Ack->_actorKey);

	// ���� ����
	// WorldContextObject �ƹ��ų� �־ ��
	// UObject�� GetWorld()�� ȣ���ϴ°� ����� ����.
	UGameplayStatics::OpenLevel(GetSampleGameInstance(), "FirstPersonMap");
}

void TrActorLoginAckProc::process(Tr* tr)
{
	TrActorLoginAck* ack = static_cast<TrActorLoginAck*>(tr);

	// ����
	{
		// �� ��Ʈ�� �׷��� �ϸ� �ɵ�
	}

	// ���� ����� ���� ����

	UWorld* World = GetSampleGameInstance()->GetWorld();

	if (nullptr == World)
	{
		// ���� ���� ����
	}

	if (GetSampleGameInstance()->GetSelfPlayerActorKey() == ack->_actorKey )
	{

	}
	else // �ٸ� �÷��̾��� ���� ����
	{

	}
}
