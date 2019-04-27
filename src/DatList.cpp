#include "DatList.h"

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink temp = new TDatLink(pVal, pLink);
	if (temp == NULL)
		throw "ListNoMem";
	return temp;
	
}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink == NULL)
	{
		if (pLink->pValue)
			delete pLink->pValue;
		delete pLink;
	}
}

TDatList::TDatList()
{
	pFirst = pLast = pCurrLink = pPrevLink = pStop = NULL;
	ListLen = 0;
	Reset();
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	PTDatLink temp;

	if (mode==FIRST)
	{
		temp = pFirst;
	}
	if (mode== LAST)
	{
		temp = pLast;
	}
	else
	{
		temp = pCurrLink;
	}
	return temp ? temp->pValue:NULL;
}

int TDatList::SetCurrentPos(int pos)
{
	Reset();
	for(int i=0 ; i<pos ; i++ , GoNext())
	return 0;
}

int TDatList::GetCurrentPos(void) const
{
	return CurrPos;
}

int TDatList::Reset(void)
{
	pPrevLink = pStop;
	if (IsEmpty())
	{
		pCurrLink = pStop;
		ListLen = -1;
	}
	else
	{
		pCurrLink = pFirst;
		ListLen = 0;
	}
	return 1;
}

int TDatList::IsListEnded(void) const
{
	
	return pCurrLink==pStop;
}

int TDatList::GoNext(void)
{
	if (pCurrLink = pStop)
		throw "ListNoMem";
	
	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink;
	CurrPos++;
}

void TDatList::InsFirst(PTDatValue pVal)
{
}

void TDatList::InsLast(PTDatValue pVal)
{
}

void TDatList::InsCurrent(PTDatValue pVal)
{
}

void TDatList::DelFirst(void)
{
}

void TDatList::DelCurrent(void)
{
}

void TDatList::DelList(void)
{
}
