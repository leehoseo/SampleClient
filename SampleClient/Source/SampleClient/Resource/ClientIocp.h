#pragma once

#ifdef _WIN32
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/PreWindowsApi.h"
#endif

#include "ThirdParty/CommonLib/Include/Iocp.h"

class ClientIocp : public Iocp
{
public:
	ClientIocp();
	virtual ~ClientIocp();

public:
	virtual void init();
};

#ifdef _WIN32
#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"
#endif