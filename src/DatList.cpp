#include "DatList.h"

// методы
PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	PTDatLink tmp = new TDatLink(pVal, pLink);
	if (tmp == NULL) throw - 1;
	return tmp;
}

void      TDatList::DelLink(PTDatLink pLink)  // удаление звена
{
	if (pLink != NULL)
	{
		if (pLink->pValue != NULL)
			delete pLink->pValue;
		delete pLink;
	}
}


TDatList::TDatList()
{
	pFirst = pLast = pCurrLink = pPrevLink = pStop = NULL;
	CurrPos = - 1;
	ListLen = 0;
}
	// доступ
PTDatValue TDatList::GetDatValue(TLinkPos mode) const // значение
{
	PTDatLink tmp;
	switch (mode)
	{
		case FIRST: {
			tmp = pFirst;
			break;
		}
		case LAST: {
			tmp = pLast;
			break;
		}
		default: {
			tmp = pCurrLink;
			break;
		}
	}
	return (tmp == NULL)? NULL : tmp->pValue;
}
	
// навигация

void TDatList::SetCurrentPos(int pos)          // установить текущее звено
{
	Reset();
	for (int i = 0; i < pos; i++)
		GoNext();
}

int TDatList::GetCurrentPos() const      // получить номер тек. звена
{
	return CurrPos;
}

void TDatList::Reset()             // установить на начало списка
{
	pPrevLink = pStop;
	if (IsEmpty())
	{
		pCurrLink = pStop;
		CurrPos = - 1;
	}
	else
	{
		pCurrLink = pFirst;
		CurrPos = 0;
	}
}
	
int TDatList::IsListEnded() const // список завершен ?
{
	return pCurrLink == pStop;
}
	
int TDatList::GoNext()                    // сдвиг вправо текущего звена
{
	if (pCurrLink == pStop) throw -1;
	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink();
	CurrPos++;
	return 0;
}
	// вставка звеньев
void TDatList::InsFirst(PTDatValue pVal) // перед первым
{
	PTDatLink tmp = GetLink(pVal, pFirst);
	if (tmp == NULL) throw - 1;
	pFirst = tmp;
	ListLen++;
	if (ListLen == 1)
	{
		pLast = tmp;
		Reset();
	}
	else if (CurrPos == 0)
		pCurrLink = tmp;
	else
		CurrPos++;
}
	
void TDatList::InsLast(PTDatValue pVal) // вставить последним 
{
	PTDatLink tmp = GetLink(pVal, pStop);
	if (tmp == NULL) throw - 1;
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
	
void TDatList::InsCurrent(PTDatValue pVal) // перед текущим 
{
	if ((IsEmpty()) || (pCurrLink == pFirst))
		InsFirst(pVal);
	else if (IsListEnded())
		InsLast(pVal);
	else
	{
		PTDatLink tmp = GetLink(pVal, pCurrLink);
		if (tmp == NULL) throw - 1;
		pCurrLink = tmp;
		pPrevLink->SetNextLink(tmp);
		ListLen++;
	}
}
	// удаление звеньев
	
void TDatList::DelFirst()    // удалить первое звено 
{
	if (IsEmpty()) throw - 1;
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
	{
		pCurrLink = pFirst;
	}
	else if (CurrPos == 1)
	{
		pPrevLink = pStop;
	}
	if (CurrPos > 0)
		CurrPos--;
}

void TDatList::DelCurrent()    // удалить текущее звено 
{
	if (pCurrLink == pStop) throw - 1;
	if (pCurrLink == pFirst) DelFirst();
	else
	{
		PTDatLink tmp = pCurrLink;
		pCurrLink = pCurrLink->GetNextDatLink();
		pPrevLink->SetNextLink(pCurrLink);
		DelLink(tmp);
		ListLen--;
	}
}

void TDatList::DelList()    // удалить весь список
{
	while (!IsEmpty())
		DelFirst();
	pFirst = pLast = pCurrLink = pPrevLink = pStop;
	CurrPos = -1;
}