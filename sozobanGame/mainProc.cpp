#include"GameMap.h"
//#include"Item.h"
//#include"ItemList.h"
#include"util.h"
#include<iostream>
#include"MyCursor.h"
#include<time.h>
#include<conio.h>
#include"H.h"
using namespace std;

// �����������(CHeroineState Ŭ������ update�޼ҵ� ȣ��) �ʿ��� �Ķ����
struct ARGS
{
	// update�� �Ķ���ͷ� �� ������ ��ü
	// &�� �ٿ��ֿ��� ������ ���� ã�� �ʰ� ���� ������ ��ü�� �� ã�ư���.(����)
	// ���� &�� �ٿ����� ������ ���α׷��� ������ ������ ���� ���ϴ� update�޼ҵ尡 ȣ����� ����
	AICharacter* AI;
	ARGS() {
		AI = new AICharacter;
	}
	// �پ��� ���µ��� �θ� Ŭ������ �����Ͽ� �� Ŭ������ ��ӹ��� ��� Ŭ������ update�޼ҵ带 ȣ�� �� �� ����
	//CHeroineState* state; // state�� ���������� �ٲٸ鼭 ���̻� �ʿ䰡 ��������.
};

DWORD WINAPI AIs(LPVOID arg)
{
	
	while (true)
	{
		// ����ü �ּҸ� ���� pArgs������ �����ϰ� �Ķ���ͷ� ���� arg�� ARGS����ü �ּ������� �ٲپ���
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // �ּ� ��
		// ����ü�� ���� �Ķ���͸� �̿��Ͽ� update�޼ҵ� ȣ�� 
		// �̶� ����ü�� CHeroineState��ü�� �÷��̾� ���°� �ٲ𶧸��� �׿� �´� ���·� �ٲ��־ �� ���¿� �´� update�޼ҵ带 ȣ���ϰ� ����.
		// ��) ���� ���¿����� �������� ��ü�� state�� �־ �������� Ŭ������ update�޼ҵ带 ȣ����.
		for (int i = 0; i < AI_num; i++)
		{
			if (pArgs->AI[i].isLive())
			{
				pArgs->AI[i].update();
			}
		}
		
		//cout << "�����忡���� state�ּҰ� : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}


//1. ���Ӹ� �����
//2. ����Ʈ �����
/*
  3. ������ ��ü�� �����Ͽ� ����Ʈ�� �߰��Ѵ�.
  4. ����Ѵ�.
*/
void main()
{
	////////////////////////
	// AI������ġ
	Point* Points = new Point[AI_num];
	Point start(1, 1);
	Point start1(17, 1);
	Point start2(4, 20);
	Point start3(17, 22);
	Points[0] = start;
	Points[1] = start1;
	Points[2] = start2;
	Points[3] = start3;

	////////////////////////
	// AI�� ���� ������ �޸� �Ҵ�(���޸�)
	AICharacter* AI = new AICharacter[AI_num];
	// AI��ü ���� �����Ϳ� ���
	for (int i = 0; i < AI_num; i++)
	{
		AI[i] = AICharacter(CTrace::getInstance(), Points[i]);
	}

	HANDLE hThreadUpdate = NULL;
	
	// ����ü �ʱ�ȭ �Ѵ�.
	ARGS* args = new ARGS();
	// AI�� ���� �����͸� �ѱ�
	args->AI = AI;

	if (hThreadUpdate == NULL)
	{
		hThreadUpdate = CreateThread(NULL, 0, AIs, args, 0, NULL);
		if (hThreadUpdate == NULL)
			return;
		CloseHandle(hThreadUpdate);
	}

	double curTime = 0.0;
	double oldTime = 0.0;

	CGameMap* gameMap = CGameMap::getInstance();

	ScreenInit();
	///////////////

	bool bStop = false;
	int mapWidth = gameMap->getWidth();
	int mapHeight = gameMap->getHeight();

	while (!bStop)
	{
		
		if (_kbhit())
		{
			int nKey = _getch();
			int cursorX = gameMap->getCursor()->getX();
			int cursorY = gameMap->getCursor()->getY();
			int tileNum = gameMap->getElement(cursorX, cursorY);
			bool isContinue = true;
			switch (nKey)
			{
			case LEFT:
				if (cursorX - 1 >= 1)
				{
					gameMap->getCursor()->goLeft();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case RIGHT:
				if (cursorX + 1 <= mapWidth - 2)
				{
					gameMap->getCursor()->goRight();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case UP:
				if (cursorY - 1 >= 1)
				{
					gameMap->getCursor()->goUp();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case DOWN:
				if (cursorY + 1 <= mapHeight - 2)
				{
					gameMap->getCursor()->goDown();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case SPACE:
				TerminateThread(hThreadUpdate, 0);
				exit(0);
				break;
			}
		}
		
		///////////////
		ScreenClear();

		gameMap->draw();
		gameMap->getCursor()->draw();
//		gameMap->getItem()->draw();
		for (int i = 0; i < AI_num; i++)
		{
			AI[i].draw();
		}
		gameMap->crash(AI);
	//	system("pause");
	
		ScreenFlipping();
		while (true){
			curTime = clock();
			if (curTime - oldTime > 33){
				oldTime = curTime;
				break;
			}
		}
	}

	ScreenRelease();
//	system("pause");
}