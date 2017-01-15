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
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "��"); // ���ۿ� �׸���
		}
		else
		{
			SetColor(14);
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "��"); // ���ۿ� �׸���
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
		// �÷��̾� ���� ��ġ
		Point curPlayerPosition = CMyCursor::getInstance()->getPlayerXY();
		
		// �÷��̾� ��ġ���� ���� �հ� ã��
		double leftUp = pow(curPlayerPosition.x, curPlayerPosition.y); // �»����
		double leftDown = pow(HEIGHT - curPlayerPosition.x, curPlayerPosition.y); // ���ϱ���
		double rightUp = pow(curPlayerPosition.x, WIDTH - curPlayerPosition.y); // ������
		double rightDown = pow(HEIGHT - curPlayerPosition.x, WIDTH - curPlayerPosition.y); // ���ϱ���
		// ���� �հ��� ����
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

// ��ǥ�������� �ִܰŸ� �̵�
void AICharacter::findPath(Point dest)
{
	// �� ������
	CGameMap* gameMap = CGameMap::getInstance();
	
	// �޸���ƽ ����
	int heuristic = 9999;
	// ���� ���
	int curNodeX = 0;
	int curNodeY = 0;
	// �����
	int startX = m_curXY.x;
	int startY = m_curXY.y;

		for (int i = 0; i < 8; i++)
		{
			curX = startX;
			curY = startY;
			// ������ȯ(8����)
			setNext(i);
			//cout << " ( " << y << " , " << x << " ) -> ";
			// ���� �ƴϸ�
			if (gameMap->getElement(curX,curY) != OBJECT)
			{
				// ���� �湮���� ��ġ�� �޸���ƽ ������
				int tempX = 0;
				int tempY = 0;
				// ���� ��ġ�� �޸���ƽ ���ϱ� x,y ��ǥ
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
				//  ���� ��ġ�� �޸���ƽ�� ���²� ������ �޸���ƽ���� ������
				if ((tempX + tempY) < heuristic)
				{
					// �̶��� ��ġ�� ����ϰ�
					curNodeX = curX;
					curNodeY = curY;
					// �޸���ƽ�� ���������� �����Ѵ�.
					heuristic = tempX + tempY;
				}

			}
		}
		// �ִܰŸ� �̵�
		setCurXY(curNodeX, curNodeY);
}

void AICharacter::trace()
{
	//cout << "if��" << getCurState() << endl;
	if (getCurState() == Trace)
	{
		cout << "������" << endl;
		CMyCursor* player = CMyCursor::getInstance();

		findPath(player->getPlayerXY());

	}
}

// 8���� �̵�
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