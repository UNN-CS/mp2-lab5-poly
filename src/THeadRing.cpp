#include "THeadRing.h"



THeadRing::THeadRing() : TDatList()
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
	TDelLink(pHead);
	pHead = nullptr;
}

void THeadRing::InsFirst(PTDatValue pVal) //вставка после заголовка 
{
	TDatList::InsFirst(pVal);
	  pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst(void)  // удаление первого звена 
{
	TDatList::DelFirst();
	  pHead->SetNextLink(pFirst);
}