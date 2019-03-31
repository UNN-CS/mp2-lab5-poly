#include "DatList.h"
#include <iostream>

TDatList::TDatList()
{
	pFirst = pLast = pStop = pPrevLink = pCurrLink = NULL;
	ListLen = 0, CurrPos = -1;
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink tmp = new TDatLink(pVal, pLink);
	return tmp;
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
	PTDatLink tmp;
	switch (mode)
	{
	case FIRST:
		tmp = pFirst;
		break;
	case LAST:
		tmp = pLast;
		break;
	default:
		tmp = pCurrLink;
		break;
	}

	return (tmp == NULL) ? NULL : tmp->pValue;
}

int TDatList::SetCurrentPos(int pos)
{
	Reset();
	for (int i = 0; i < pos; i++)
		GoNext();
	return 0;

}

int TDatList::GetCurrentPos() const
{
	return CurrPos;
}

int TDatList::Reset()
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

	return 0;
}

int TDatList::GoNext()
{
	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink(); ////
	CurrPos++;
	return 0;
}

int TDatList::IsListEnded() const
{
	return pCurrLink == pStop;
}

void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink tmp = GetLink(pVal, pFirst);
	pFirst = tmp;
	ListLen++;
	if (ListLen == 1)
	{
		pLast = tmp;
		Reset();
	}
	else
	{
		if (CurrPos == 0)
		{
			pCurrLink = tmp;
		}
		else
		{
			CurrPos++;
		}
	}
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink tmp = GetLink(pVal, pStop);

	if (pLast != NULL)
		pLast->SetNextLink(tmp);
	pLast = tmp;
	ListLen++;
	if (ListLen == 1)
	{
		pFirst = tmp;
		Reset();
	}
	if (IsListEnded())
		pCurrLink = tmp;
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (IsEmpty() || (pCurrLink == pFirst))
		InsFirst(pVal);
	else if (pPrevLink == pStop)
		InsLast(pVal);
	else if (pPrevLink == pStop)///
		;
	else
	{
		PTDatLink tmp = GetLink(pVal, pCurrLink);
		if (tmp == NULL)
			;
		else
		{
			pCurrLink = tmp;
			pPrevLink->SetNextLink(tmp);
			ListLen++;
		}
	}
}

void TDatList::DelFirst()
{
	if (IsEmpty())
		return;
	else
	{
		PTDatLink tmp = pFirst;
		pFirst = pFirst->GetNextDatLink();
		DelLink(tmp);
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
}

void TDatList::DelCurrent()
{
	if (pCurrLink == pStop)
		return;
	else if (pCurrLink == pFirst)
		DelFirst();
	else
	{
		PTDatLink tmp = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		pPrevLink->SetNextLink(pCurrLink);
		DelLink(tmp);
		ListLen--;
		if (pCurrLink == pLast)
		{
			pLast = pPrevLink;
			pCurrLink = pStop;
		}
	}
}

void TDatList::DelList()
{
	while (!IsEmpty())
		DelFirst();
	pFirst = pLast; pPrevLink = pCurrLink = pStop;
	CurrPos = -1;
}
