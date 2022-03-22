#pragma once

#ifdef _WIN32
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/PreWindowsApi.h"
#endif

#include "Iocp.h"

class TrNetworkConnectReq;
class ClientIocp : public Iocp
{
public:
	ClientIocp();
	virtual ~ClientIocp();

public:
	virtual void init();
	virtual void onConnect();
	void release();
	void connnectServer(TrNetworkConnectReq* tr);

	bool checkConnect();

private:
	bool isConnect = false;
};

#ifdef _WIN32
#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"
#endif