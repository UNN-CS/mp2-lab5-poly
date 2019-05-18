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

	if (mode == FIRST)
	{
		temp = pFirst;
	}
	if (mode == LAST)
	{
		temp = pLast;
	}
	else
	{
		temp = pCurrLink;
	}
	return temp ? temp->pValue : NULL;
}

int TDatList::SetCurrentPos(int pos)
{
	Reset();
	for (int i = 0; i < pos; i++, GoNext())
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

	return pCurrLink == pStop;
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
	PTDatLink temp = GetLink(pVal, pFirst);
	if (temp == NULL)
		throw "ListNoMem";
	pFirst = temp;
	ListLen++;
	if (ListLen == 1)
	{
		pLast = temp;
		Reset();
	}
	else if (CurrPos == 0)
		pCurrLink = temp;
	else
		CurrPos++;
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink temp = GetLink(pVal, pStop);
	if (temp == NULL)
		throw "ListNoMem";
	if (pLast != NULL)
		pLast->SetNextLink(temp);
	pLast = temp;
	ListLen++;
	if (ListLen == 1)
		pFirst = temp;
	Reset();
	if (IsListEnded())
	{
		pCurrLink = temp;
	}
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (IsEmpty() || (pCurrLink == pFirst))
		InsFirst(pVal);
	else if (IsListEnded())
		InsLast(pVal);
	else if (pPrevLink == pStop)
		throw "ListNoMem";
	else
	{
		PTDatLink temp = GetLink(pVal, pCurrLink);
		if (temp == NULL)
			throw "ListNoMem";
		pCurrLink = temp;
		pPrevLink->SetNextLink(temp);
		ListLen++;
	}
}

void TDatList::DelFirst(void)
{
	if (IsEmpty());
	throw "ListNoMem";
	PTDatLink temp = pFirst;
	pFirst = pFirst->GetNextDatLink();
	DelLink(temp);
	ListLen--;
	if (IsEmpty())
	{
		pLast = pStop;
		Reset();
	}
	else if (CurrPos == 0)
		pCurrLink = pFirst;
	else if (CurrPos == 1)
		pPrevLink = pStop;
	if (CurrPos > 0)
		CurrPos--;
}

void TDatList::DelCurrent(void)
{
	if (pCurrLink == pStop)
		throw "ListNoMem";
	else if (pCurrLink == pFirst)
		DelFirst();
	else
	{
		PTDatLink temp = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		pPrevLink->SetNextLink(pCurrLink);
		DelLink(temp);
		ListLen--;
		if (pCurrLink == pLast)
		{
			pLast = pPrevLink;
			pCurrLink = pStop;
		}
	}
}

void TDatList::DelList(void)
{
	while (!IsEmpty())
		DelFirst();
	pFirst = pLast = pPrevLink = pCurrLink = pStop;
	CurrPos = -1;
}
