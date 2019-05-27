#include "tdatlist.h"

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

TDatList::TDatList()
{
	pFirst = pLast = pStop = nullptr;
	ListLen = 0; 
	Reset();
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink tmp = new TDatLink(pVal, pLink); //выделение звена
	if (tmp == nullptr) throw - 1;

	return tmp;
}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink != nullptr)
	{
		if (pLink->pValue != nullptr)
			delete pLink->pValue;
		delete pLink;
	}
	
}

/// методы доступа

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	PTDatLink tmp;
	switch (mode)
	{
	case FIRST: tmp = pFirst; break;
	case LAST: tmp = pLast; break;
	default: tmp = pCurrLink; break;
	}
	return (tmp == nullptr) ? nullptr : tmp->pValue;
}

/// методы навигации

void TDatList::SetCurrentPos(int pos)
{
	if (pos<0 || pos>ListLen) throw "Incorrect position";
	Reset();
	for (int i = 0; i < pos; ++i) GoNext();
}

int TDatList::GetCurrentPos() const
{
	return CurrPos;
}



void TDatList::GoNext()
{
	if (pCurrLink == pStop)
		throw "error";
	else
	{
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		CurrPos++;
	}
}

int TDatList::IsListEnded()const
{
	return pCurrLink == pStop;
}

///вставка звеньев

void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink tmp = GetLink(pVal, pFirst);
	if (tmp == nullptr) throw "Memory error";
	else {
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
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink tmp = GetLink(pVal, pStop);
	if (tmp == nullptr) throw "Memory error";
	else
	{
		if (pLast != nullptr) pLast->SetNextLink(tmp);
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
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (IsEmpty() || pCurrLink == pFirst) InsFirst(pVal);
	else if (IsListEnded()) InsLast(pVal);
	else if (pPrevLink == pStop) throw "ere";
	else
	{
		PTDatLink tmp = GetLink(pVal, pCurrLink);
		if (tmp == nullptr) throw "no memory";
		pCurrLink = tmp;
		pPrevLink->SetNextLink(tmp);
		ListLen++;
	}
}

///методы удаления звеньев

void TDatList::DelFirst()
{
	if (IsEmpty()) return;
	else
	{
		PTDatLink tmp = pFirst;
		pFirst = pFirst->GetNextDatLink();
		DelLink(tmp);
		--ListLen;
		if (IsEmpty())
		{
			pLast = pStop;
			Reset();
		}
		else if (CurrPos == 0) 
			pCurrLink == pFirst;
		else if (CurrPos == 1) 
			pPrevLink == pStop;
		if (CurrPos > 0) 
			CurrPos--;
	}
}

void TDatList::DelCurrent()
{
	if (pCurrLink == pStop) return;
	else if (pCurrLink == pFirst) DelFirst();
	else
	{
		// чето тут какая-то хуйня....
		PTDatLink tmp = pCurrLink;
//////////////////////////////////////////////////////////////////////
		if (pCurrLink == pLast)    ////
		{						   ////
			pLast = pPrevLink;	   ////
			pCurrLink = pStop;	   ////
		}						   ////
///////////////////////////////////////////////////////////////////////
		else {
			pCurrLink = pCurrLink->GetNextDatLink();
			pPrevLink->SetNextLink(pCurrLink);
			DelLink(tmp);
			ListLen--;
		}
/*		if (pCurrLink == pLast)
		{
			pLast = pPrevLink;
			pCurrLink = pStop;
		}*/
	}
}

void TDatList::DelList()
{
	while (!IsEmpty()) DelFirst();
	pFirst = pLast = pCurrLink = pPrevLink = pStop;
	CurrPos = -1;
}
