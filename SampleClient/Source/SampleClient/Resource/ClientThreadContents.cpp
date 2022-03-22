#include "ClientThreadContents.h"


ClientThreadContents::ClientThreadContents()
{
}

ClientThreadContents::~ClientThreadContents()
{
}

void ClientThreadContents::insertAndRunThread()
{
	_networkThread.init(1);
	_dispatcherThread.init(1);
}

void ClientThreadContents::notifyOne(const ThreadType& type)
{
	__noop;
}

