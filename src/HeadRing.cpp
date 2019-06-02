#include "HeadRing.h"

THeadRing::THeadRing()
{
	pHead = GetLink();
	pFirst = GetLink();
	pStop = GetLink();
	ListLen = 0;
	CurrPos = -1;
}

THeadRing::~THeadRing()
{
	DelList();
	DelLink(pHead);
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
