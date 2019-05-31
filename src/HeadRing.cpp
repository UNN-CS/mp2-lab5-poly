#include "HeadRing.h"

THeadRing::THeadRing() : TDatList()
{
    pHead = new TDatLink();
    pStop = pHead;
    pHead->SetNextLink(pFirst);
    ListLen = 0;
}

THeadRing::~THeadRing()
{
    DelList();
    DelLink(pHead);
    pHead = NULL;
}

void THeadRing::InsFirst(PTDatValue pVal)
{
    TDatList::InsFirst(pVal);
    pHead->pNext = pFirst;
}

void THeadRing::DelFirst()
{
    TDatList::DelFirst();
    pHead->SetNextLink(pFirst);
}

bool THeadRing::IsEmpty() const
{
    return (pFirst == NULL) || (pFirst == pStop);
}

void THeadRing::InsCurrent(PTDatValue pVal)
{
    if (pCurrLink == pStop)
        InsLast(pVal);
    else
        TDatList::InsCurrent(pVal);
}