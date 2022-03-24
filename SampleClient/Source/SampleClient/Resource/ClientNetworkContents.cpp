#include "ClientNetworkContents.h"
#include "TrAuth.h"
#include "SystemManager.h"
#include "ClientIocp.h"
#include "SampleGameInstance.h"

ClientNetworkContents::ClientNetworkContents()
{
}

ClientNetworkContents::~ClientNetworkContents()
{
}


void ClientNetworkContents::requestConnectToServer()
{
	ClientIocp* iocp = static_cast<ClientIocp*>(SystemManager::getInstance()->getIcop());
	iocp->init();

	TrNetworkConnectReq req;
	req.set();
	iocp->connnectServer(&req);
}

void ClientNetworkContents::requestDisConnectFromServer()
{
	TrNetworkDisConnectReq* req = new TrNetworkDisConnectReq();
	req->set(GetSampleGameInstance()->GetSelfPlayerActorKey());
	sendToServer(req, 0);
}