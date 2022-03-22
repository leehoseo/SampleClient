#pragma once
#include "Proc.h"

class Tr;
class TrNetworkConnectAckProc : public Proc
{
public:
	TrNetworkConnectAckProc() : Proc() {}
	virtual ~TrNetworkConnectAckProc() {}

public:
	virtual void process(Tr* tr);
};

class TrActorLoginAckProc : public Proc
{
public:
	TrActorLoginAckProc() : Proc() {}
	virtual ~TrActorLoginAckProc() {}

public:
	virtual void process(Tr* tr);
};