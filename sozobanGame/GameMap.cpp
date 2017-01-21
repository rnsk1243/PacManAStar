#include"H.h"
CGameMap::CGameMap()
{
}


CGameMap::~CGameMap()
{
}

CGameMap * CGameMap::getInstance()
{
	static CGameMap* instance = new CGameMap(19, 24, 21, CMyCursor::getInstance()/*, CItemList::getInstance()*/);
	if (instance)
		return instance;
	return nullptr;
}

void CGameMap::initMap()
{
	//srand((unsigned int)time(NULL));
	// º®
	m_gameMap[2][2] = OBJECT;m_gameMap[3][2] = OBJECT;m_gameMap[2][3] = OBJECT;m_gameMap[3][3] = OBJECT;
	m_gameMap[1][9] = OBJECT;m_gameMap[2][9] = OBJECT;m_gameMap[2][5] = OBJECT;m_gameMap[2][6] = OBJECT;
	m_gameMap[2][7] = OBJECT;m_gameMap[2][11] = OBJECT;m_gameMap[2][12] = OBJECT;
	m_gameMap[2][13] = OBJECT;m_gameMap[2][15] = OBJECT;m_gameMap[2][16] = OBJECT;m_gameMap[3][5] = OBJECT;
	m_gameMap[3][6] = OBJECT;m_gameMap[3][7] = OBJECT;m_gameMap[3][9] = OBJECT;m_gameMap[3][11] = OBJECT;
	m_gameMap[3][12] = OBJECT;m_gameMap[3][13] = OBJECT;m_gameMap[3][15] = OBJECT;m_gameMap[3][16] = OBJECT;
	m_gameMap[5][2] = OBJECT;m_gameMap[5][3] = OBJECT;m_gameMap[5][5] = OBJECT;m_gameMap[5][7] = OBJECT;
	m_gameMap[5][8] = OBJECT;m_gameMap[5][9] = OBJECT;m_gameMap[5][10] = OBJECT;m_gameMap[5][11] = OBJECT;
	m_gameMap[5][13] = OBJECT;m_gameMap[5][15] = OBJECT;m_gameMap[5][16] = OBJECT;m_gameMap[6][5] = OBJECT;
	m_gameMap[6][9] = OBJECT;m_gameMap[6][13] = OBJECT;m_gameMap[7][1] = OBJECT;m_gameMap[7][2] = OBJECT;
	m_gameMap[7][3] = OBJECT;m_gameMap[7][5] = OBJECT;m_gameMap[7][6] = OBJECT;m_gameMap[7][7] = OBJECT;
	m_gameMap[7][9] = OBJECT;m_gameMap[7][11] = OBJECT;m_gameMap[7][12] = OBJECT;m_gameMap[7][13] = OBJECT;
	m_gameMap[7][15] = OBJECT;m_gameMap[7][16] = OBJECT;m_gameMap[7][17] = OBJECT;m_gameMap[8][1] = OBJECT;
	m_gameMap[8][2] = OBJECT;m_gameMap[8][3] = OBJECT;m_gameMap[8][5] = OBJECT;m_gameMap[8][13] = OBJECT;
	m_gameMap[8][15] = OBJECT;m_gameMap[8][16] = OBJECT;m_gameMap[8][17] = OBJECT;m_gameMap[9][1] = OBJECT;
	m_gameMap[9][2] = OBJECT;m_gameMap[9][3] = OBJECT;m_gameMap[9][5] = OBJECT;m_gameMap[9][7] = OBJECT;
	m_gameMap[9][8] = OBJECT;m_gameMap[9][10] = OBJECT;m_gameMap[9][11] = OBJECT;m_gameMap[9][13] = OBJECT;
	m_gameMap[9][15] = OBJECT;m_gameMap[9][16] = OBJECT;m_gameMap[9][17] = OBJECT;m_gameMap[10][1] = OBJECT;
	m_gameMap[10][2] = OBJECT;m_gameMap[10][3] = OBJECT;m_gameMap[10][5] = OBJECT;m_gameMap[10][7] = OBJECT;
	m_gameMap[10][11] = OBJECT;m_gameMap[10][13] = OBJECT;m_gameMap[10][15] = OBJECT;m_gameMap[10][16] = OBJECT;
	m_gameMap[10][17] = OBJECT;m_gameMap[11][7] = OBJECT;m_gameMap[11][11] = OBJECT;m_gameMap[12][1] = OBJECT;
	m_gameMap[12][2] = OBJECT;m_gameMap[12][3] = OBJECT;m_gameMap[12][5] = OBJECT;m_gameMap[12][7] = OBJECT;
	m_gameMap[12][11] = OBJECT;m_gameMap[12][13] = OBJECT;m_gameMap[12][15] = OBJECT;m_gameMap[12][16] = OBJECT;
	m_gameMap[12][17] = OBJECT;m_gameMap[13][1] = OBJECT;m_gameMap[13][2] = OBJECT;m_gameMap[13][3] = OBJECT;
	m_gameMap[13][5] = OBJECT;m_gameMap[13][7] = OBJECT;m_gameMap[13][8] = OBJECT;m_gameMap[13][9] = OBJECT;
	m_gameMap[13][10] = OBJECT;m_gameMap[13][11] = OBJECT;m_gameMap[13][13] = OBJECT;m_gameMap[13][15] = OBJECT;
	m_gameMap[13][16] = OBJECT;m_gameMap[13][17] = OBJECT;m_gameMap[14][1] = OBJECT;m_gameMap[14][2] = OBJECT;
	m_gameMap[14][3] = OBJECT;m_gameMap[14][5] = OBJECT;m_gameMap[14][13] = OBJECT;m_gameMap[14][15] = OBJECT;
	m_gameMap[14][16] = OBJECT;m_gameMap[14][17] = OBJECT;m_gameMap[15][1] = OBJECT;m_gameMap[15][2] = OBJECT;
	m_gameMap[15][3] = OBJECT;m_gameMap[15][5] = OBJECT;m_gameMap[15][7] = OBJECT;m_gameMap[15][8] = OBJECT;
	m_gameMap[15][9] = OBJECT;m_gameMap[15][10] = OBJECT;m_gameMap[15][11] = OBJECT;m_gameMap[15][13] = OBJECT;
	m_gameMap[15][15] = OBJECT;m_gameMap[15][16] = OBJECT;m_gameMap[15][17] = OBJECT;m_gameMap[16][9] = OBJECT;
	m_gameMap[17][2] = OBJECT;m_gameMap[17][3] = OBJECT;m_gameMap[17][5] = OBJECT;m_gameMap[17][6] = OBJECT;
	m_gameMap[17][7] = OBJECT;m_gameMap[17][9] = OBJECT;m_gameMap[17][11] = OBJECT;m_gameMap[17][12] = OBJECT;
	m_gameMap[17][13] = OBJECT;m_gameMap[17][15] = OBJECT;m_gameMap[17][16] = OBJECT;m_gameMap[18][3] = OBJECT;
	m_gameMap[18][15] = OBJECT;m_gameMap[18][9] = BLANK;m_gameMap[19][1] = OBJECT;m_gameMap[19][3] = OBJECT;
	m_gameMap[19][5] = OBJECT;m_gameMap[19][7] = OBJECT;m_gameMap[19][8] = OBJECT;m_gameMap[19][9] = OBJECT;
	m_gameMap[19][10] = OBJECT;m_gameMap[19][11] = OBJECT;m_gameMap[19][13] = OBJECT;m_gameMap[19][15] = OBJECT;
	m_gameMap[19][17] = OBJECT;m_gameMap[20][5] = OBJECT;m_gameMap[20][9] = OBJECT;m_gameMap[20][13] = OBJECT;
	m_gameMap[21][2] = OBJECT;m_gameMap[21][3] = OBJECT;m_gameMap[21][4] = OBJECT;m_gameMap[21][5] = OBJECT;
	m_gameMap[21][6] = OBJECT;m_gameMap[21][7] = OBJECT;m_gameMap[21][9] = OBJECT;m_gameMap[21][11] = OBJECT;
	m_gameMap[21][12] = OBJECT;m_gameMap[21][13] = OBJECT;m_gameMap[21][14] = OBJECT;m_gameMap[21][15] = OBJECT;
	m_gameMap[21][16] = OBJECT;

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			if (x == 0 || y == 0 || x == m_width - 1 || y == m_height - 1)
				m_gameMap[y][x] = OBJECT;
			else if (m_gameMap[y][x] != OBJECT)
			{
				m_gameMap[y][x] = TARGET;
			}
		}
	}

}

void CGameMap::draw()
{
	char* tileImg[] = { " ", "¡¤", "¢Ì" };
	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
		{
			if (m_gameMap[y][x]==2)
			{
				SetColor(11);
				ScreenPrint(x * 2, y, tileImg[m_gameMap[y][x]]);
			}
			else
			{
				SetColor(15);
				ScreenPrint(x*2,y,tileImg[m_gameMap[y][x]]);
			}
		}
}
// max´Â ÃÑ AIÀÇ °¹¼ö
void CGameMap::crash(AICharacter* AIs)
{
	int cursorX = m_cursor->getX();
	int cursorY = m_cursor->getY();

	for (int i = 0; i < AI_num; i++)
	{
		int x = AIs[i].getCurXY().x;
		int y = AIs[i].getCurXY().y;
		//cout << "x = " << x << " / " << "y = " << y << endl;
		
		if (cursorX == x && cursorY == y)
		{
			if (!m_cursor->isPowerFull())
			{
				cout << "ÆÐ¹è..." << endl;
				exit(0);
			}
			else {
						// ÀÚ»ì
						AIs[i].suicide();
						setElement(x, y, BLANK);
						m_cursor->EatAIPluse();
						isVictory();
			}
		}
	}


}

bool CGameMap::isVictory()
{
	//cout << m_cursor->getEatAI() << "½Â¸®" << endl;
	if (m_cursor->getEatAI() >= AI_num)
	{
		cout << "½Â¸®" << endl;
	//	TerminateThread()
		ExitProcess(1);
		return true;
	}
	return false;
}


/*
if (m_item->getItem(2)->getX() != resultX || m_item->getItem(2)->getY() != resultY)
if (m_item->getItem(3)->getX() != resultX || m_item->getItem(3)->getY() != resultY)
if (m_item->getItem(4)->getX() != resultX || m_item->getItem(4)->getY() != resultY)
*/