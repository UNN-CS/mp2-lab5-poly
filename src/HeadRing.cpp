#include "HeadRing.h"

THeadRing::THeadRing() 
{
	InsLast();
	pHead = pFirst;
	ListLen = 0;
	pStop = pHead;
	Reset();
	pFirst->SetNextLink(pFirst);
}
THeadRing::~THeadRing() 
{
	TDatList::DelList();
	DelLink(pHead);
	pHead = NULL;
}
// вставка звеньев
void THeadRing::InsFirst(PTDatValue pVal) // после заголовка
{
	TDatList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
}
// удаление звеньев
void THeadRing::DelFirst()
{
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}// удалить первое звено
