#include "DatList.h"

TDatList::TDatList()
{
	pFirst = pLast = pCurrLink = pPrevLink = pStop = NULL;
	ListLen = 0;
	CurrPos = -1;
	SetRetCode(ListEmpty);
};

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink tmp = new TDatLink(pVal, pLink);
	if (tmp == NULL) SetRetCode(ListNoMem);
	else SetRetCode(ListOK);
	return tmp;

}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink != NULL) {
		if (pLink->pValue != NULL) delete pLink->pValue;
		delete pLink;
	}
	SetRetCode(ListOK);
}
PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	PTDatLink tmp;
	if (mode == FIRST)
		tmp = pFirst;
	else if (mode == CURRENT)
		tmp = pCurrLink;
	else if (mode == LAST)
		tmp = pLast;
	return tmp->pValue;
};

void TDatList::SetCurrentPos(int pos)
{
	for (int i = 0; i < pos; i++)
		GoNext();
};

int TDatList::GetCurrentPos(void) const
{
	return CurrPos;
}


int TDatList::IsListEnded(void) const
{
	return pCurrLink == pStop;
}

int TDatList::GoNext(void)
{
	if (pCurrLink == pStop)
	{
		SetRetCode(ListNoPos);
		return ListNoPos;
	}
	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink();
	CurrPos++;
}

void TDatList::Reset(void)
{
	pPrevLink = pStop;
	if (IsEmpty())
	{
		pCurrLink = pStop; CurrPos = -1;
	}
	else
	{
		pCurrLink = pFirst; CurrPos = 0;
	}
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
	if (IsEmpty()) SetRetCode(ListEmpty);
	else
	{
		PTDatLink tmp = pFirst;
		pFirst = pFirst->GetNextDatLink();
		DelLink(tmp);
		ListLen--;
		if (IsEmpty())
		{
			pLast = pStop;
			SetRetCode(ListEmpty);
			Reset();
		}
		else
		{
			if (CurrPos == 0)
				pCurrLink = pFirst;
			if (CurrPos == 1)
					pPrevLink = pStop;
			if (CurrPos > 0)
				CurrPos--;
		}
	}

}

void TDatList::DelCurrent(void)
{
	if (IsEmpty()) SetRetCode(ListEmpty); 
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
			DelLink(tmp);
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
