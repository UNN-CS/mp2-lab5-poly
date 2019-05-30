#include "DatList.h"
#include <stdexcept> 

using namespace std;

TDatList::TDatList()
{
	pFirst = pLast = pCurrLink = pPrevLink = pStop = nullptr;
	CurrPos = -1;
	ListLen = 0;
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink tmp = new TDatLink(pVal, pLink);
	return tmp;
}

void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink == pStop)
		throw invalid_argument("Link doesnt't exist!");
	delete pLink->pValue;
	delete pLink;
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	if (mode == CURRENT)	
		if (pCurrLink == nullptr)
			throw invalid_argument("Can't get value! List is empty!");
		else
			return pCurrLink->GetDatValue();
}

int TDatList::Reset(void)
{
	if (!this->IsEmpty())
	{
		CurrPos = 0;
		pCurrLink = pFirst;
		pPrevLink = pStop;
		return 0;
	}
}

int TDatList::SetCurrentPos(int pos)
{
	if (pos >= ListLen || pos < 0)
		throw out_of_range("Argument is out of range!");
	this->Reset();
	for (int i = 0; i < pos; i++)
		GoNext();
	return 0;
}

int TDatList::IsListEnded(void) const
{
	return pCurrLink == pLast;
}

int TDatList::GoNext(void)
{
	if (pCurrLink != nullptr)
	{
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		CurrPos++;
		return 0;
	}
	else
		return 1;
}

void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink tmp = this->GetLink(pVal, pFirst);
	if (pCurrLink == pFirst)
		if (!this->IsEmpty())
			pPrevLink = tmp;
		else
		{
			pLast = tmp;
			pCurrLink = tmp;
		}
	pFirst = tmp;
	ListLen++;
	CurrPos++;
}

void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink tmp = GetLink(pVal, pStop);
	if (this->IsEmpty())
	{
		pFirst = tmp;
		pCurrLink = tmp;
		CurrPos++;
	}
	else
		pLast->SetNextLink(tmp);
	pLast = tmp;
	ListLen++;
}

void TDatList::InsCurrent(PTDatValue pVal)
{
	if (pCurrLink == pFirst)
		InsFirst(pVal);
	else
	{
		PTDatLink tmp = GetLink(pVal, pCurrLink);
		pPrevLink->SetNextLink(tmp);
		pPrevLink = tmp;
		ListLen++;
		CurrPos++;
	}
}

void TDatList::DelFirst(void)
{
	if (this->IsEmpty())
		throw invalid_argument("Can't delete first! List is empty!");
	if (pFirst == pLast)
		pLast = pCurrLink = pStop;
	else if (pFirst == pCurrLink)
	{
		pCurrLink = pFirst->GetNextDatLink();
		CurrPos++;
	}
	else if (pFirst == pPrevLink)
	{
		pPrevLink = pStop;
	}

	PTDatLink tmp = pFirst->GetNextDatLink();
	DelLink(pFirst);
	pFirst = tmp;
	CurrPos--;
	ListLen--;
}


void TDatList::DelCurrent(void)
{
	if (this->IsEmpty())
		throw invalid_argument("Can't delete current! List is empty!");
	if (pCurrLink == pFirst)
		DelFirst();
	else
	{
		pPrevLink->SetNextLink(pCurrLink->pNext);
		PTDatLink tmp = pCurrLink->GetNextDatLink();
		DelLink(pCurrLink);
		pCurrLink = tmp;
		ListLen--;
	}
}

void TDatList::DelList(void)
{
	while (!this->IsEmpty())
		DelFirst();
	pFirst = pLast = pCurrLink = pPrevLink = pStop;
}