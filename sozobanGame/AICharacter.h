#pragma once
#include"State.h"
#include<string>

struct Point
{
	int x, y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int _x, int _y)
	{
		x = _x; y = _y;
	}
};

class AICharacter
{
	// ���� ����
	CState* m_pCurState;
	// ���� ��ġ
	Point m_curXY;
	// ���� ��ǥ��
	Point* m_patrolPoints;
	// ���� ��ǥ��
	Point* m_escapePoints;
	// ���� ��ǥ�� �ϴ� ��ǥ �ε���
	int m_curState; // 0 = Patrol , 1 = Trace
	double curTime = 0.0;
	double oldTime = 0.0;
	bool isLife = true;
	bool isFinish = false;
	// ���� Ȯ������ ��ǥ
	int curX;
	int curY;
public:
	AICharacter(CState* state, Point startPoint);
	AICharacter() {}
	~AICharacter();
	// ���� ��ǥ ��ǥ ������
	int getCurState() { return m_curState; }
	void changeState(int state) { m_curState = state; }
	void update();
	void draw();
	void trace();
	void setNext(int nextIndex);
	void changeState(CState* pNewState);
	void delay();
	void left();
	void right();
	void up();
	void down();
	void setCurXY(Point xy) { m_curXY = xy; }
	void setCurXY(int x, int y) { m_curXY.x = x; m_curXY.y = y; }
	Point getCurXY() { return m_curXY; }
	void suicide() 
	{ 
		isLife = false; 

		m_curXY.x = 0;
		m_curXY.y = 0;
	}
	void escape();
	bool isLive() { return isLife; }
	void findPath(Point dest);
};

