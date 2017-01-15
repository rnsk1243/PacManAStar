#pragma once
#include "State.h"
class CEscape :
	public CState
{
	CEscape();
public:
	~CEscape();
	static CEscape* getInstance();
	void Enter(AICharacter* ch);
	void Execute(AICharacter* ch);
	void Exit(AICharacter* ch);
	State getCurState() { return Escape_; }
};

