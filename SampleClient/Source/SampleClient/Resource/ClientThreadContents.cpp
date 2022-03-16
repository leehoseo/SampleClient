#include "ClientThreadContents.h"


ClientThreadContents::ClientThreadContents()
{
}

ClientThreadContents::~ClientThreadContents()
{
}

void ClientThreadContents::insertAndRunThread()
{
	{
		_networkThread.init(1);
	}
	{
		_dispatcherThread.init(1);
	}
}

void ClientThreadContents::notifyOne(const ThreadType& type)
{
	switch (type)
	{
	case ThreadType::eNetwork:
		_networkThread.notifyOne();
		break;
	case ThreadType::eDispatcher:
		_dispatcherThread.notifyOne();
		break;
	case ThreadType::eCount:
		break;
	default:
		break;
	}
}

