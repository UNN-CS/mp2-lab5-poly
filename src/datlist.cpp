#include "../include/datlist.h"

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink) const
{
  return new TDatLink(pVal, pLink);
}

void TDatList::DelLink(PTDatLink pLink)
{
  if(pLink != nullptr)
  {
    if(pLink->pValue != nullptr)
      delete pLink->pValue;

    delete pLink;
  }

  SetRetCode(ListOK);
}

TDatList::TDatList()
  :pStop(nullptr), pFirst(pStop), pLast(pStop), ListLen(0)
{
  Reset();
}

PTDatValue TDatList::GetDatValue(TLinkPos mode)
{
  PTDatLink t;
  switch(mode)
  {
  case FIRST:
    t = pFirst;
    break;
  case CURRENT:
    t = pCurrLink;
    break;
  case LAST:
    t = pLast;
    break;
  }

  return (t == nullptr) ? (nullptr) : (t->pValue);
}

int TDatList::SetCurrentPos(int pos)
{
  Reset();

  for(int i = 0; i < pos; ++i)
    GoNext();

  SetRetCode(ListOK);

  return RetCode;
}

int TDatList::GetCurrentPos() const
{ return CurrPos; }

int TDatList::Reset()
{
  pPrevLink = pStop;
  pCurrLink = pFirst;
  if(IsEmpty())
  {
    CurrPos = -1;
    SetRetCode(ListEmpty);
  }
  else
  {
    CurrPos = 0;
    SetRetCode(ListOK);
  }

  return RetCode;
}

bool TDatList::IsListEnded() const
{ return pCurrLink == pStop; }

int TDatList::GoNext()
{
  if(IsListEnded())
  {
    SetRetCode(ListNoPos);
    throw ListNoPos;
  }
  else
  {
    SetRetCode(ListOK);
    pPrevLink = pCurrLink;
    pCurrLink = pCurrLink->GetNextDatLink();
    ++CurrPos;
  }

  return RetCode;
}

void TDatList::InsFirst(PTDatValue pVal)
{
  PTDatLink t = GetLink(pVal, pFirst);

  if(t == nullptr)
  {
    SetRetCode(ListNoMem);
    throw ListNoMem;
  }
  else
  {
    pFirst = t;
    ++ListLen;
    if(ListLen == 1)
    {
      pLast = pFirst;
      Reset();
    }
    else if(CurrPos == 0)
    {
      pCurrLink = pFirst;
    }
    else
    {
      ++CurrPos;
    }

    SetRetCode(ListOK);
  }
}

void TDatList::InsLast(PTDatValue pVal)
{
  PTDatLink t = GetLink(pVal, pStop);
  if(t == nullptr)
  {
    SetRetCode(ListNoMem);
    throw ListNoMem;
  }
  else
  {
    if(pLast != nullptr)
      pLast->SetNextLink(t);

    pLast = t;
    ++ListLen;

    if(ListLen == 1)
    {
      pFirst = pLast;
      Reset();
    }

    if(IsListEnded())
      pCurrLink = pLast;
  }
}

void TDatList::InsCurrent(PTDatValue pVal)
{
  if(IsEmpty() || pCurrLink == pFirst)
  {
    InsFirst(pVal);
  }
  else if(IsListEnded())
  {
    InsLast(pVal);
  }
  else if(pPrevLink == pStop)
  {
    SetRetCode(ListNoPos);
    throw ListNoPos;
  }
  else
  {
    PTDatLink t = GetLink(pVal, pCurrLink);
    if(t == nullptr)
    {
      SetRetCode(ListNoMem);
      throw ListNoMem;
    }
    else
    {
      pCurrLink = t;
      pPrevLink->SetNextLink(pCurrLink);
      ++ListLen;
      SetRetCode(ListOK);
    }
  }
}

void TDatList::DelFirst()
{
  if(IsEmpty())
  {
    SetRetCode(ListEmpty);
    throw ListEmpty;
  }
  else
  {
    PTDatLink t = pFirst;
    pFirst = pFirst->GetNextDatLink();
    DelLink(t);
    t = nullptr;
    --ListLen;
    if(ListLen == 0)
    {
      pLast = pStop;
      pCurrLink = pStop;
      CurrPos = -1;
    }
    else if(CurrPos == 0)
    {
      pCurrLink = pFirst;
    }
    else if(CurrPos == 1)
    {
      pPrevLink = pStop;
    }

    if(CurrPos > 0)
      --CurrPos;

    SetRetCode(ListOK);
  }
}

void TDatList::DelCurrent()
{
  if(pCurrLink == pStop)
  {
    SetRetCode(ListNoPos);
    throw ListNoPos;
  }
  else if(pCurrLink == pFirst)
  {
    DelFirst();
  }
  else
  {
    PTDatLink t = pCurrLink;
    pCurrLink = pCurrLink->GetNextDatLink();
    pPrevLink->SetNextLink(pCurrLink);
    DelLink(t);

    SetRetCode(ListOK);
  }
}

void TDatList::DelList()
{
  Reset();
  while(!IsEmpty())
    DelFirst();
  Reset();
}

