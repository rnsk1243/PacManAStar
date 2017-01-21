#pragma once
#include"util.h"
#include"MyCursor.h"
//#include"ItemList.h"
#include<time.h>
#include<stdlib.h>
class CGameMap
{
	CMyCursor* m_cursor;
	//CItemList* m_item;
	int **m_gameMap;
	int m_width;
	int m_height;
	int m_targetNum;
	int m_exit = 0;
	CGameMap(int w, int h, int tn, CMyCursor* cu/*, CItemList* item*/)
		:m_width(w), m_height(h), m_targetNum(tn), m_cursor(cu)//, m_item(item)
	{
		m_gameMap = new int*[h];
		for (int i = 0; i < h; i++)
			m_gameMap[i] = new int[w];
		initMap();
	}
public:
	CGameMap();
	~CGameMap();
	static CGameMap* getInstance();
	void initMap();
	int getWidth(){ return m_width; }
	int getHeight(){ return m_height; }
	int getElement(int x, int y){ return m_gameMap[y][x]; }
	void setElement(int x, int y, int val){ m_gameMap[y][x] = val; }
	void draw();
	void crash(AICharacter* AIs);
	CMyCursor* getCursor(){ return m_cursor; }
	//CItemList* getItem(){ return m_item; }
	bool isVictory();
};

