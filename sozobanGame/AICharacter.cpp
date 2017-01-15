#include"H.h"
#include"MyCursor.h"
#include<math.h>

AICharacter::AICharacter(CState * state, Point startPoint):
	m_pCurState(state), m_curXY(startPoint), m_curState(Trace), curX(0), curY(0)
{
}

AICharacter::~AICharacter()
{
}

CGameMap* gameMap = CGameMap::getInstance();


void AICharacter::update()
{
	if (m_pCurState && isLife)
	{
		delay();
		m_pCurState->Execute(this);
	}
	else 
	{
		//gameMap->setElement(m_curXY.x, m_curXY.y, BLANK);
		return;
	}
}

void AICharacter::draw()
{
	if (isLife)
	{
		if (CMyCursor::getInstance()->isPowerFull())
		{
			SetColor(9);
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "♨"); // 버퍼에 그리기
		}
		else
		{
			SetColor(14);
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "♨"); // 버퍼에 그리기
		}
	}
	else
	{
		return;
	}
}


void AICharacter::changeState(CState * pNewState)
{
	m_pCurState->Exit(this);
	m_pCurState = pNewState;
	m_pCurState->Enter(this);
}

void AICharacter::delay()
{
	while (true) {
		curTime = clock();
		if (curTime - oldTime > 33) {
			oldTime = curTime;
			break;
		}
	}
}

void AICharacter::left()
{
	m_curXY.x--;
}
void AICharacter::right()
{
	m_curXY.x++;
}
void AICharacter::up()
{
	m_curXY.y--;
}
void AICharacter::down()
{
	m_curXY.y++;
}

void AICharacter::escape()
{
	if (getCurState() == Escape_)
	{
		// 플레이어 현재 위치
		Point curPlayerPosition = CMyCursor::getInstance()->getPlayerXY();
		
		// 플레이어 위치에서 가장 먼곳 찾기
		double leftUp = pow(curPlayerPosition.x, curPlayerPosition.y); // 좌상기준
		double leftDown = pow(HEIGHT - curPlayerPosition.x, curPlayerPosition.y); // 좌하기준
		double rightUp = pow(curPlayerPosition.x, WIDTH - curPlayerPosition.y); // 우상기준
		double rightDown = pow(HEIGHT - curPlayerPosition.x, WIDTH - curPlayerPosition.y); // 우하기준
		// 가장 먼곳의 길이
		double temp = max(max(leftUp, leftDown), max(rightUp, rightDown));

		if (temp == leftUp)
		{
			findPath(Point(1, 1));
			return;
		}
		else if (temp == leftDown)
		{
			findPath(Point(HEIGHT - 2, 1));
			return;
		}
		else if (temp == rightUp)
		{
			findPath(Point(1, WIDTH - 2));
			return;
		}
		else if (temp == rightDown)
		{
			findPath(Point(HEIGHT - 2, WIDTH - 2));
			return;
		}
	}
}

// 목표지점으로 최단거리 이동
void AICharacter::findPath(Point dest)
{
	// 멥 가져옴
	CGameMap* gameMap = CGameMap::getInstance();
	
	// 휴리스틱 보관
	int heuristic = 9999;
	// 현재 노드
	int curNodeX = 0;
	int curNodeY = 0;
	// 출발점
	int startX = m_curXY.x;
	int startY = m_curXY.y;

		for (int i = 0; i < 8; i++)
		{
			curX = startX;
			curY = startY;
			// 방향전환(8방향)
			setNext(i);
			//cout << " ( " << y << " , " << x << " ) -> ";
			// 벽이 아니면
			if (gameMap->getElement(curX,curY) != OBJECT)
			{
				// 현재 방문중인 위치의 휴리스틱 보관용
				int tempX = 0;
				int tempY = 0;
				// 현재 위치의 휴리스틱 구하기 x,y 좌표
				if (curX > dest.x)
				{
					tempX = (curX - dest.x) * 10;
				}
				else {
					tempX = (dest.x - curX) * 10;
				}
				if (curY > dest.y)
				{
					tempY = (curY - dest.y) * 10;
				}
				else {
					tempY = (dest.y - curY) * 10;
				}
				//  현재 위치의 휴리스틱이 여태껏 지나온 휴리스틱보다 작으면
				if ((tempX + tempY) < heuristic)
				{
					// 이때의 위치를 기억하고
					curNodeX = curX;
					curNodeY = curY;
					// 휴리스틱을 작은것으로 갱신한다.
					heuristic = tempX + tempY;
				}

			}
		}
		// 최단거리 이동
		setCurXY(curNodeX, curNodeY);
}

void AICharacter::trace()
{
	//cout << "if밖" << getCurState() << endl;
	if (getCurState() == Trace)
	{
		cout << "추적중" << endl;
		CMyCursor* player = CMyCursor::getInstance();

		findPath(player->getPlayerXY());

	}
}

// 8방향 이동
void AICharacter::setNext(int nextIndex)
{
	switch (nextIndex)
	{
	case 0:
		curY--;
		break;
	case 1:
		curX++;
		curY--;
		break;
	case 2:
		curX++;
		break;
	case 3:
		curX++;
		curY++;
		break;
	case 4:
		curY++;
		break;
	case 5:
		curX--;
		curY++;
		break;
	case 6:
		curX--;
		break;
	case 7:
		curX--;
		curY--;
		break;
	}
}