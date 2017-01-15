#include "Item.h"


CItem::CItem()
{
}


CItem::~CItem()
{
}

void CItem::draw()
{
	char* itemImg = "¢¾";
	if (m_bTarget)
	{
		SetColor(12);
		ScreenPrint(m_x * 2, m_y, itemImg);
	}
	else
	{
		SetColor(15);
		ScreenPrint(m_x * 2, m_y, itemImg);
	}
	
}