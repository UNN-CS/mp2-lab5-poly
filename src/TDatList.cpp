#include "TDatList.h"



TDatList::TDatList()
{
	pFirst = pLast = pCurrLink = pPrevLink = pStop = NULL;
	ListLen = 0;
	CurrPos = -1;
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	return new TDatLink(pVal, pLink);
}

void TDatList::TDelLink(PTDatLink pLink)
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
	case FIRST: tmp = pFirst; break;
	case LAST: tmp = pLast; break;
	default: tmp = pCurrLink; break;
	}
	if (tmp == NULL) throw - 1;
	return tmp->pValue;
}

int TDatList::Reset(void)
{
	pPrevLink = pStop;
	if (IsEmpty())
	{
		pCurrLink = pStop;
		CurrPos = -1;
		return 0;
	}
	pCurrLink = pFirst;
	CurrPos = 0;
	return 1;
}

int TDatList::GoNext(void)
{
	if (pCurrLink == pStop) return 0;
	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink();
	CurrPos++;
	return 1;
}

int TDatList::IsListEnded(void) const
{
	return pCurrLink == pStop;
}

int TDatList::GetCurrentPos(void) const
{
	return CurrPos;
}

int TDatList::SetCurrentPos(int pos)
{
	if (pos < 0 || pos >= ListLen) return 0;
	Reset();
	for (int i = 0; i < pos; i++)
		GoNext();
	return 1;
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
		pCurrLink = tmp;
	   else
		CurrPos++;
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
	else
	{
		if (IsListEnded())
			InsLast(pVal);
		else
			if (pPrevLink == pStop)
				throw - 1;
			else
			{
				PTDatLink tmp = GetLink(pVal, pCurrLink);
				pPrevLink->SetNextLink(tmp);
				pPrevLink = tmp;
				ListLen++;
			}
	}
}

void TDatList::DelFirst(void)
{
	if (IsEmpty()) throw - 1;
	 else
	{
	   PTDatLink tmp = pFirst;
	   pFirst = pFirst->GetNextDatLink();
	   TDelLink(tmp);
	   ListLen--;
		if (IsEmpty())
		{
			pLast = pStop;
			Reset();
		}
		else
		{
		   if (CurrPos == 0)
				pCurrLink = pFirst;
			else
				if (CurrPos == 1)
					pPrevLink = pStop;
			if (CurrPos > 0)
				CurrPos--;
		}
	}
}

void TDatList::DelCurrent(void)
{
	if (IsEmpty()) throw - 1;
	else
	{
		if (pCurrLink == pFirst)
			DelFirst();
		else
		{
			if (pCurrLink == pLast)
			pLast = pPrevLink;
			PTDatLink tmp = pCurrLink;
			pCurrLink = pCurrLink->GetNextDatLink();
			pPrevLink->SetNextLink(pCurrLink);
			TDelLink(tmp);
			ListLen--;
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