#pragma once
#include"util.h"

class CItem
{
	int m_x;
	int m_y;
	bool m_bTarget;
	int m_value;
public:
	CItem();
	~CItem();
	CItem(int x, int y) :m_x(x), m_y(y), m_bTarget(false), m_value(1)
	{}
	int getX(){ return m_x; }
	int getY(){ return m_y; }
	void setXY(int x, int y){ m_x = x; m_y = y; }

	bool isTarget(){ return m_bTarget; }
	void setTarget(bool t){ m_bTarget = t; }
	void draw();

	int getValue(){ return m_value; }
};

