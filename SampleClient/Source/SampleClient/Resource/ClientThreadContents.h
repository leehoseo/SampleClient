#pragma once
#include "ThreadContents.h"
#include "NetworkThread.h"
#include "DispatcherThread.h"

class ClientThreadContents : public ThreadContents
{
public:
	ClientThreadContents();
	virtual ~ClientThreadContents();

public:
	virtual void insertAndRunThread();
	virtual void notifyOne(const ThreadType& type);

private:
	NetworkThread _networkThread;
	DispatcherThread _dispatcherThread;
};

