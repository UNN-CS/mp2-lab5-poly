#include "../include/headring.h"

THeadRing::THeadRing(): TDatList()
{
  InsLast();
  pHead = pFirst;
  ListLen = 0;
  *const_cast<PTDatLink*>(&pStop) = pHead;
  Reset();
}

THeadRing::~THeadRing()
{
  TDatList::DelList();
  DelLink(pHead);
}

void THeadRing::InsFirst(PTDatValue pVal)
{
  TDatList::InsFirst(pVal);
  if(RetCode == ListOK)
    pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst()
{
  TDatList::DelFirst();
  pHead->SetNextLink(pFirst);
}


