#pragma once

#include"AICharacter.h"

class CMyCursor
{
	int m_x;
	int m_y;
	CMyCursor();
	// ¸î°³ ¸Ô¾î¾ß ½êÁö³ª?
	int targetAmount;
	double startPowerTime = 0.0;
	double endPowerTime = 0.0;
	int eatAI_amount = 0;
public:
	~CMyCursor();
	static CMyCursor* getInstance();
	int getX() { return m_x; }
	int getY() { return m_y; }
	void setXY(int x, int y) { m_x = x; m_y = y; }
	void goLeft();
	void goRight();
	void goUp();
	void goDown();
	void draw();
	void eat();
	Point getPlayerXY();
	int getTargetAmount() { return targetAmount; }
	bool isPowerFull() { return targetAmount > POWERFULL; }
	void powerTime();
	int getEatAI() { return eatAI_amount; }
	void EatAIPluse() { eatAI_amount++; }
};

