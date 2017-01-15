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
	AICharacter& AI;
	// 다양한 상태들의 부모 클래스를 선언하여 이 클래스를 상속받은 모든 클래스의 update메소드를 호출 할 수 있음
	//CHeroineState* state; // state를 정적변수로 바꾸면서 더이상 필요가 없어졌다.
};

DWORD WINAPI AI_1(LPVOID arg)
{
	
	while (true)
	{
		// 구조체 주소를 담을 pArgs변수를 선언하고 파라미터로 들어온 arg를 ARGS구조체 주소형으로 바꾸어줌
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // 주소 찍어봄
		// 구조체로 들어온 파라미터를 이용하여 update메소드 호출 
		// 이때 구조체의 CHeroineState객체를 플레이어 상태가 바뀔때마다 그에 맞는 상태로 바꿔주어서 그 상태에 맞는 update메소드를 호출하게 만듬.
		// 예) 점프 상태에서는 점프상태 객체를 state에 넣어서 점프상태 클래스의 update메소드를 호출함.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else 
		{
			return 0;
		}
		//cout << "스레드에서의 state주소값 : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}

DWORD WINAPI AI_2(LPVOID arg)
{

	while (true)
	{
		// 구조체 주소를 담을 pArgs변수를 선언하고 파라미터로 들어온 arg를 ARGS구조체 주소형으로 바꾸어줌
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // 주소 찍어봄
		// 구조체로 들어온 파라미터를 이용하여 update메소드 호출 
		// 이때 구조체의 CHeroineState객체를 플레이어 상태가 바뀔때마다 그에 맞는 상태로 바꿔주어서 그 상태에 맞는 update메소드를 호출하게 만듬.
		// 예) 점프 상태에서는 점프상태 객체를 state에 넣어서 점프상태 클래스의 update메소드를 호출함.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else
		{
			return 0;
		}
		//cout << "스레드에서의 state주소값 : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}

DWORD WINAPI AI_3(LPVOID arg)
{

	while (true)
	{
		// 구조체 주소를 담을 pArgs변수를 선언하고 파라미터로 들어온 arg를 ARGS구조체 주소형으로 바꾸어줌
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // 주소 찍어봄
		// 구조체로 들어온 파라미터를 이용하여 update메소드 호출 
		// 이때 구조체의 CHeroineState객체를 플레이어 상태가 바뀔때마다 그에 맞는 상태로 바꿔주어서 그 상태에 맞는 update메소드를 호출하게 만듬.
		// 예) 점프 상태에서는 점프상태 객체를 state에 넣어서 점프상태 클래스의 update메소드를 호출함.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else
		{
			return 0;
		}
		//cout << "스레드에서의 state주소값 : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}

DWORD WINAPI AI_4(LPVOID arg)
{

	while (true)
	{
		// 구조체 주소를 담을 pArgs변수를 선언하고 파라미터로 들어온 arg를 ARGS구조체 주소형으로 바꾸어줌
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // 주소 찍어봄
		// 구조체로 들어온 파라미터를 이용하여 update메소드 호출 
		// 이때 구조체의 CHeroineState객체를 플레이어 상태가 바뀔때마다 그에 맞는 상태로 바꿔주어서 그 상태에 맞는 update메소드를 호출하게 만듬.
		// 예) 점프 상태에서는 점프상태 객체를 state에 넣어서 점프상태 클래스의 update메소드를 호출함.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else
		{
			return 0;
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

	Point start(1, 1);
	////////////////////////
	////////////////////////

	Point start1(17, 1);
	////////////////////////
	////////////////////////

	Point start2(4, 20);
	////////////////////////
	////////////////////////

	Point start3(17, 22);
	////////////////////////
	AICharacter AI(CTrace::getInstance(), start);
	AICharacter AI1(CTrace::getInstance(), start1);
	AICharacter AI2(CTrace::getInstance(), start2);
	AICharacter AI3(CTrace::getInstance(), start3);

	HANDLE hThreadUpdate = NULL;
	HANDLE hThreadUpdate1 = NULL;
	HANDLE hThreadUpdate2 = NULL;
	HANDLE hThreadUpdate3 = NULL;
	
	// 구조체 초기화 한다.
	ARGS args = { AI };
	ARGS args1 = { AI1 };
	ARGS args2 = { AI2 };
	ARGS args3 = { AI3 };

	if (hThreadUpdate == NULL)
	{
		hThreadUpdate = CreateThread(NULL, 0, AI_1, &args, 0, NULL);
		if (hThreadUpdate == NULL)
			return;
		CloseHandle(hThreadUpdate);
	}

	if (hThreadUpdate1 == NULL)
	{
		hThreadUpdate1 = CreateThread(NULL, 0, AI_2, &args1, 0, NULL);
		if (hThreadUpdate1 == NULL)
			return;
		CloseHandle(hThreadUpdate1);
	}

	if (hThreadUpdate2 == NULL)
	{
		hThreadUpdate2 = CreateThread(NULL, 0, AI_3, &args2, 0, NULL);
		if (hThreadUpdate2 == NULL)
			return;
		CloseHandle(hThreadUpdate2);
	}

	if (hThreadUpdate3 == NULL)
	{
		hThreadUpdate3 = CreateThread(NULL, 0, AI_4, &args3, 0, NULL);
		if (hThreadUpdate3 == NULL)
			return;
		CloseHandle(hThreadUpdate3);
	}

	AICharacter** AIs = new AICharacter*[1];
	for (int i = 0; i < 4; i++)
	{
		AIs[i] = new AICharacter[1];
	}
	AIs[0] = &AI;
	AIs[1] = &AI1;
	AIs[2] = &AI2;
	AIs[3] = &AI3;
	////////////////////////
	double curTime = 0.0;
	double oldTime = 0.0;

	CGameMap* gameMap = CGameMap::getInstance();

	/*for (int i = 0; i < 5; i++)
	{
		int x = 2 + rand() % (gameMap->getWidth() - 4);
		int y = 2 + rand() % (gameMap->getHeight() - 4);
		gameMap->getItem()->insertItem(i, CItem(x, y));
	}
	srand((unsigned int)time(NULL));*/
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
				TerminateThread(hThreadUpdate1, 0);
				TerminateThread(hThreadUpdate2, 0);
				TerminateThread(hThreadUpdate3, 0);
				exit(0);
				break;
			}
		}
		
		///////////////
		ScreenClear();

		gameMap->draw();
		gameMap->getCursor()->draw();
//		gameMap->getItem()->draw();
		AI.draw();
		AI1.draw();
		AI2.draw();
		AI3.draw();
		gameMap->crash(AIs, 4);
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