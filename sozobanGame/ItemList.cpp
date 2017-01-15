#include "ItemList.h"


CItemList::CItemList()
{
}


CItemList::~CItemList()
{
}

CItemList * CItemList::getInstance()
{
	static CItemList* instance = new CItemList(5);
	if (instance)
		return instance;
	return nullptr;
}

void CItemList::insertItem(int pos, CItem item)
{
	if (isFull()) return;
	for (int cur = m_numItem - 1; cur >= pos; cur--)
		m_list[cur + 1] = m_list[cur];
	m_list[pos] = item;
	m_numItem++;
}
void CItemList::removeItem(int pos)
{
	if (isEmpty()) return;
	for (int cur = pos; cur < m_numItem; cur++)
		m_list[cur] = m_list[cur + 1];
	m_numItem--;
}
CItem* CItemList::getItem(int pos)
{
	return (isEmpty() || pos < 0 || pos > m_numItem) ? nullptr : &m_list[pos];
}

void CItemList::draw()
{
	for (int i = 0; i < m_numItem; i++)
	{

		m_list[i].draw();
	}
}