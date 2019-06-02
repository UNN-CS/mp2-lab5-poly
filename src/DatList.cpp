#include <stdexcept>
#include "DatList.h"

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	return new TDatLink(pVal, pLink);
}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink != nullptr)
	{
		if (pLink->pValue)
		{
			delete pLink->pValue;
		}
		delete pLink;
	}
}

TDatList::TDatList()
{
	pFirst = nullptr;
	pLast = nullptr;
	pCurrLink = nullptr;
	pPrevLink = nullptr;
	pStop = nullptr;
	CurrPos = -1;
	ListLen = 0;
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	if (pFirst != pStop)
		switch (mode)
		{
		case FIRST:
			return pFirst->GetDatValue();
			break;
		case CURRENT:
			return pCurrLink->GetDatValue();
			break;
		case LAST:
			return pLast->GetDatValue();
			break;
		}
	return nullptr;
}

int TDatList::SetCurrentPos(int pos)
{
	if (ListLen == 0)
		throw std::logic_error("ERROR! EMPTY LIST!!");
	if (pos < 0 || pos >= ListLen)
		throw std::out_of_range("ERROR! POS IS OUT OF RANGE!");
	Reset();
	for (int i = 0; i < pos; i++)
		GoNext();
	CurrPos = pos;
	return 0;
}

int TDatList::GetCurrentPos(void) const
{
	return CurrPos;
}

int TDatList::Reset(void)
{
	if (!IsEmpty())
	{
		pCurrLink = pFirst;
		pPrevLink = pStop;
		CurrPos = 0;
	}
	return 0;
}

int TDatList::IsListEnded(void) const
{
	return (pCurrLink == pStop) && (pPrevLink == pLast);
}

int TDatList::GoNext(void)
{
	if (pCurrLink)
	{
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		CurrPos++;
		return 0;
	}
	return 1;
}

void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink temp = GetLink(pVal, pFirst);
	if (temp)
	{
		temp->SetNextLink(pFirst);
		pFirst = temp;
		ListLen++;
		if (CurrPos == 0)
			pCurrLink = temp;
		else if (ListLen == 1)
		{
			pLast = temp;
			Reset();
		}
		else
			CurrPos++;
	}
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink temp = GetLink(pVal, pStop);
	if (pLast)
		pLast->SetNextLink(temp);
	else
	{
		pFirst = temp;
		pCurrLink = temp;
		CurrPos = 0;
	}
	pLast = temp;
	ListLen++;
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (pCurrLink == pFirst)
		InsFirst(pVal);
	else
	{
		if (IsListEnded())
			InsLast(pVal);
		else
		{
			PTDatLink temp = GetLink(pVal, pFirst);
			if (temp)
			{
				pPrevLink->SetNextLink(temp);
				pPrevLink = temp;
				ListLen++;
				CurrPos++;
			}
		}
	}
}

void TDatList::DelFirst(void)
{
	if (IsEmpty())
		throw "ERROR! EMPTY LIST!";
	else
	{
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
		if (CurrPos)
			CurrPos--;
	}
}

void TDatList::DelCurrent(void)
{
	if (IsEmpty())
		throw "ERROR! EMPTY LIST!";
	else
	{
		if (pCurrLink == pFirst)
			DelFirst();
		else
		{
			PTDatLink temp = pCurrLink;
			if (pCurrLink == pLast)
			{
				pLast = pPrevLink;
				CurrPos = 0;
			}
			pCurrLink = pCurrLink->GetNextDatLink();
			pPrevLink->SetNextLink(pCurrLink);
			DelLink(temp);
			ListLen--;
		}
	}
}

void TDatList::DelList(void)
{
	while (!IsEmpty())
		DelFirst();
	pPrevLink = pCurrLink = pFirst = pLast = pStop;
}
