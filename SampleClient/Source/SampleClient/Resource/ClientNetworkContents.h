#pragma once
#include "NetworkContents.h"

class ClientNetworkContents : public NetworkContents
{
public:
	ClientNetworkContents();
	virtual ~ClientNetworkContents();

	void requestConnectToServer();
	void requestDisConnectFromServer();
};


