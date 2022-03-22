#include "ClientNetworkContents.h"
#include "Tr.h"
#include "TrAuthProc.h"

ClientNetworkContents::ClientNetworkContents()
{
}

ClientNetworkContents::~ClientNetworkContents()
{
}

void ClientNetworkContents::recvTr(Tr* tr)
{
#define CaseHandle(trId) case TrId::##trId: { trId##Proc proc; proc.process(tr); } break;

	switch (tr->_trId)
	{
		CaseHandle(TrNetworkConnectAck);
		CaseHandle(TrActorLoginAck);
	}
}