#include "../include/headring.h"

THeadRing::THeadRing(): TDatList()
{
  InsFirst();
  pHead = pFirst;
  ListLen = 0;
  pStop = pHead;
  //*const_cast<PTDatLink*>(&pStop) = pHead;
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


