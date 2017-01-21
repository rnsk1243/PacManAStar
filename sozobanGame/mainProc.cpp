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

// 스레드생성에(CHeroineState 클래스의 update메소드 호출) 필요한 파라미터
struct ARGS
{
	// update의 파라미터로 들어갈 히로인 객체
	// &을 붙여주여야 엉뚱한 곳을 찾지 않고 내가 생성한 객체를 잘 찾아간다.(추측)
	// 만약 &을 붙여주지 않으면 프로그램이 죽지는 않으나 내가 원하는 update메소드가 호출되지 않음
	AICharacter* AI;
	ARGS() {
		AI = new AICharacter;
	}
	// 다양한 상태들의 부모 클래스를 선언하여 이 클래스를 상속받은 모든 클래스의 update메소드를 호출 할 수 있음
	//CHeroineState* state; // state를 정적변수로 바꾸면서 더이상 필요가 없어졌다.
};

DWORD WINAPI AIs(LPVOID arg)
{
	
	while (true)
	{
		// 구조체 주소를 담을 pArgs변수를 선언하고 파라미터로 들어온 arg를 ARGS구조체 주소형으로 바꾸어줌
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // 주소 찍어봄
		// 구조체로 들어온 파라미터를 이용하여 update메소드 호출 
		// 이때 구조체의 CHeroineState객체를 플레이어 상태가 바뀔때마다 그에 맞는 상태로 바꿔주어서 그 상태에 맞는 update메소드를 호출하게 만듬.
		// 예) 점프 상태에서는 점프상태 객체를 state에 넣어서 점프상태 클래스의 update메소드를 호출함.
		for (int i = 0; i < AI_num; i++)
		{
			if (pArgs->AI[i].isLive())
			{
				pArgs->AI[i].update();
			}
		}
		
		//cout << "스레드에서의 state주소값 : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}


//1. 게임맵 만든다
//2. 리스트 만든다
/*
  3. 아이템 객체를 생성하여 리스트에 추가한다.
  4. 출력한다.
*/
void main()
{
	////////////////////////
	// AI시작위치
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
	// AI를 담을 포인터 메모리 할당(힙메모리)
	AICharacter* AI = new AICharacter[AI_num];
	// AI객체 생성 포인터에 담기
	for (int i = 0; i < AI_num; i++)
	{
		AI[i] = AICharacter(CTrace::getInstance(), Points[i]);
	}

	HANDLE hThreadUpdate = NULL;
	
	// 구조체 초기화 한다.
	ARGS* args = new ARGS();
	// AI를 담은 포인터를 넘김
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