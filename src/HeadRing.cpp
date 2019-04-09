#include "HeadRing.h"

THeadRing::THeadRing()
{
	pFirst = pStop = pHead = GetLink();
	CurrPos = -1;
	ListLen = 0;
}

THeadRing::~THeadRing()
{
	DelList();
	delete pHead;
}

void THeadRing::InsFirst(PTDatValue pVal)
{
	TDatList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst(void)
{
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}