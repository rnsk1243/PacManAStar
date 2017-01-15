#include"H.h"

CMyCursor::CMyCursor()
{
	m_x = 9;
	m_y = 18;
	//m_x = 1;
	//m_y = 1;
	targetAmount = 0;
}


CMyCursor::~CMyCursor()
{
}

CMyCursor * CMyCursor::getInstance()
{
	static CMyCursor* instance = new CMyCursor();
	if (instance)
		return instance;
	return nullptr;
}
CGameMap* map = CGameMap::getInstance();

void CMyCursor::goLeft()
{
	int temp = m_x;
	temp--;

	if (map->getElement(temp, m_y) == OBJECT)
	{
		return;
	}
	m_x--;
	eat();
}
void CMyCursor::goRight()
{
	int temp = m_x;
	temp++;

	if (map->getElement(temp, m_y) == OBJECT)
	{
		return;
	}
	m_x++;
	eat();
}
void CMyCursor::goUp()
{
	int temp = m_y;
	temp--;
	
	if (map->getElement(m_x, temp) == OBJECT)
	{
		return;
	}
	m_y--;
	eat();
}

void CMyCursor::goDown()
{
	int temp = m_y;
	temp++;

	if (map->getElement(m_x, temp) == OBJECT)
	{
		return;
	}
	m_y++;
	eat();
}


void CMyCursor::draw()
{
	powerTime();
	//	m_x=0;
	//	m_y=0;
	if (targetAmount < POWERFULL)
	{
		// 노랑
		SetColor(14);
	}
	else if (targetAmount >= POWERFULL)
	{
		// 빨강
		SetColor(12);
	}
	
	ScreenPrint(m_x * 2, m_y, "★"); // 버퍼에 그리기
}

void CMyCursor::eat()
{
	if (map->getElement(m_x, m_y) == TARGET)
	{
		map->setElement(m_x, m_y, BLANK);
		if (!isPowerFull())
		{
			targetAmount++;
			if (isPowerFull())
			{
				// 시작시간 저장
				//startPowerTime = clock();
				//endPowerTime = startPowerTime;
			}
		}
	}
}

Point CMyCursor::getPlayerXY()
{
	return Point(m_x, m_y);
}

void CMyCursor::powerTime()
{
//	cout << "startPowerTime = " << startPowerTime << endl;
//	cout << "clock() = " << clock() << endl;
//	cout << "targetAmount = " << targetAmount << endl;
	// 시작시간 저장
	endPowerTime = clock();
	if (startPowerTime + 10000.0 < endPowerTime)
	{
		targetAmount = 0;
		startPowerTime = endPowerTime;
	}
}

