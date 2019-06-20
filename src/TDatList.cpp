#include "TDatList.h"

TDatList::TDatList()
{
	pFirst = pLast = pStop = NULL;
	ListLen = 0;
	Reset();
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink temp = new TDatLink(pVal, pLink);
	if (temp == NULL)
		throw "List doesn't have memory";
	return temp;
}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink != NULL)
	{
		if (pLink->pValue != NULL)
			delete pLink->pValue;
		delete pLink;
	}
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	PTDatLink temp;
	switch (mode)
	{
	case FIRST:
		temp = pFirst;
		break;
	case LAST:
		temp = pLast;
		break;
	default:
		temp = pCurrLink;
		break;
	}
	return (temp == NULL) ? NULL : temp->pValue;
}

void TDatList::SetCurrentPos(int pos)
{
	Reset();
	for (int i = 0; i < pos; i++, GoNext())
		;
}

int TDatList::GetCurrentPos(void) const
{
	return CurrPos;
}

void TDatList::Reset()
{
	pPrevLink = pStop;
	if (IsEmpty())
	{
		pCurrLink = pStop;
		CurrPos = -1;
	}
	else
	{
		pCurrLink = pFirst;
		CurrPos = 0;
	}
}

void TDatList::GoNext(void)
{
	if (pCurrLink != pStop)
	{
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		CurrPos++;
	}
}

int TDatList::IsListEnded(void) const
{
	return pCurrLink == pStop;
}

void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink temp = GetLink(pVal, pFirst);
	if (temp != NULL)
	{
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
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink temp = GetLink(pVal, pStop);
	if (temp != NULL)
	{
		if (pLast != NULL)
			pLast->SetNextLink(temp);
		pLast = temp;
		ListLen++;
		if (ListLen == 1)
		{
			pFirst = temp;
			Reset();
		}
		if (IsListEnded())
			pCurrLink = temp;
	}
	else
		throw "ListNoMem";
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (IsEmpty() || pCurrLink == pFirst)
		InsFirst(pVal);
	else if (IsListEnded())
		InsLast(pVal);
	else if (pPrevLink == pStop)
		throw "List No Mem";
	else
	{
		PTDatLink temp = GetLink(pVal, pCurrLink);
		if (temp != NULL)
		{
			pCurrLink = temp;
			pPrevLink->SetNextLink(temp);
			ListLen++;
		}
	}
}

void TDatList::DelFirst(void)
{
	if (IsEmpty())
		throw "List is empty";
	else
	{
		PTDatLink temp = pFirst;
		pFirst = (PTDatLink)pFirst->GetNextLink();
		DelLink(temp);
		ListLen--;
	}
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
		throw "No link in current position";
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
	pFirst = pLast = pStop = pCurrLink = pPrevLink;
	CurrPos = -1;
}
