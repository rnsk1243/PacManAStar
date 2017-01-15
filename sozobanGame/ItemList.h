#pragma once
#include"Item.h"

class CItemList
{
	CItem* m_list;
	int m_maxItem; // 리스트의 최대 배열 크기
	int m_numItem; // 리스트에 저장된 item의 갯수
	CItemList(int max) :m_maxItem(max), m_numItem(0)
	{
		m_list = new CItem[max];
	}
public:
	CItemList();
	~CItemList();
	static CItemList* getInstance();
	void insertItem(int pos, CItem item);
	void removeItem(int pos);
	CItem* getItem(int pos);

	bool isEmpty(){ return m_numItem == 0; }
	bool isFull(){ return m_numItem == m_maxItem; }
	void draw();

	int getMaxItem(){ return m_maxItem; }
};

