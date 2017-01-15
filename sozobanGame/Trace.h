#pragma once
#include "State.h"
class CTrace :
	public CState
{
	CTrace();
public:
	~CTrace();
	static CTrace* getInstance();
	void Enter(AICharacter* ch);
	void Execute(AICharacter* ch);
	void Exit(AICharacter* ch);
	State getCurState() { return Trace; }
};

