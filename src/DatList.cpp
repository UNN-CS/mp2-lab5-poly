#include "DatList.h"



TDatList::TDatList()
{
	pFirst = pLast = pStop = pPrevLink = pCurrLink = NULL;
	list_len = 0;
	Reset();
}
/*---------------------------------------------------------------------------*/
PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink temp = new TDatLink(pVal, pLink);
	if (temp == NULL)
		throw "ListNoMem";
	return temp;
}
/*---------------------------------------------------------------------------*/
void TDatList::DelLink(PTDatLink pLink)
{
	if (pLink != NULL)
	{
		if (pLink->pValue)
			delete pLink->pValue;
		delete pLink;
	}
}
/*---------------------------------------------------------------------------*/
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

	return temp ? temp->pValue : NULL;
}
/*---------------------------------------------------------------------------*/
void TDatList::SetCurrentPos(int pos)
{
	Reset();
	for (int i = 0; i < pos; i++, GoNext());
}
/*---------------------------------------------------------------------------*/
int TDatList::GetCurrentPos() const
{
	return curr_pos;
}
/*---------------------------------------------------------------------------*/
int TDatList::Reset()
{
	pPrevLink = pStop;

	if (IsEmpty())
	{
		pCurrLink = pStop;
		curr_pos = -1;
	}
	else
	{
		pCurrLink = pFirst;
		curr_pos = 0;
	}

	return 1;
}
/*---------------------------------------------------------------------------*/
void TDatList::GoNext()
{
	if (pCurrLink == pStop)
		throw "ListNoMem";

	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink();
	curr_pos++;
}
/*---------------------------------------------------------------------------*/
int TDatList::IsListEnded() const
{
	return pCurrLink == pStop;
}
/*---------------------------------------------------------------------------*/
void TDatList::InsFirst(PTDatValue pVal)
{
	PTDatLink temp = GetLink(pVal, pFirst);
	if (temp == NULL)
		throw "ListNoMem";

	pFirst = temp;
	list_len++;
	if (list_len == 1)
	{
		pLast = temp;
		Reset();
	}
	else if (curr_pos == 0)
		pCurrLink = temp;
	else
		curr_pos++;
}
/*---------------------------------------------------------------------------*/
void TDatList::InsLast(PTDatValue pVal)
{
	PTDatLink temp = GetLink(pVal, pStop);
	if (temp == NULL)
		throw "ListNoMem";

	if (pLast != NULL)
		pLast->SetNextLink(temp);

	pLast = temp;
	list_len++;

	if (list_len == 1)
	{
		pFirst = temp;
		Reset();
	}
	if (IsListEnded())
		pCurrLink = temp;
}
/*---------------------------------------------------------------------------*/
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
		list_len++;
	}
}
/*---------------------------------------------------------------------------*/
void TDatList::DelFirst()
{
	if (IsEmpty())
		throw "ListNoMem";

	PTDatLink temp = pFirst;
	pFirst = pFirst->GetNextDatLink();
	DelLink(temp);
	list_len--;

	if (IsEmpty())
	{
		pLast = pStop;
		Reset();
	}
	else if (curr_pos == 0)
		pCurrLink = pFirst;
	else if (curr_pos == 1)
		pPrevLink = pStop;
	if (curr_pos > 0)
		curr_pos--;
}
/*---------------------------------------------------------------------------*/
void TDatList::DelCurrent()
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
		list_len--;

		if (pCurrLink == pLast)
		{
			pLast = pPrevLink;
			pCurrLink = pStop;
		}
	}
}
/*---------------------------------------------------------------------------*/
void TDatList::DelList()
{
	while (!IsEmpty())
		DelFirst();
	pFirst = pLast = pPrevLink = pCurrLink = pStop;
	curr_pos = -1;
}