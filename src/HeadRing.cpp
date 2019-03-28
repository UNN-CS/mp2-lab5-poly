#include "HeadRing.h"

THeadRing::THeadRing() 
{
	InsLast();
	pHead = pLast;
	pStop = pHead;
	pFirst->SetNextLink(pFirst);
	ListLen = 0;	
}

THeadRing::~THeadRing() 
{
	TDatList::DelList();
	DelLink(pHead);
	pHead = nullptr;
}

void THeadRing::InsFirst(PTDatValue pVal) 
{
	TDatList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst() {
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}