//Списки
#include "DatList.h"

TDatList::TDatList() {
    pFirst = pLast = pStop = pPrevLink = pCurrLink = NULL;
	ListLen = 0, CurrPos = -1;
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink) {
    PTDatLink tmp = new TDatLink(pVal, pLink); //выделение звена
    if(tmp == NULL)
        throw ListNoMem;
    return tmp;
}

void TDatList::DelLink (PTDatLink pLink) { //удаление звена
    if(pLink != NULL)
    {
        if(pLink->pValue != NULL)
            delete pLink->pValue;
        delete pLink;
    }
}

//методы доступа

PTDatValue TDatList::GetDatValue(TLinkPos mode) const { //значение
    PTDatLink tmp;
    switch(mode) {
        case FIRST: tmp = pFirst; break;
        case LAST: tmp = pLast; break;
        default: tmp = pCurrLink; break;
    }
    return (tmp == NULL)?NULL:tmp->pValue;
}

//методы навигации
void TDatList::SetCurrentPos(int pos) { //установить текущее звено
    Reset();
    for(int i = 0; i < pos; i++)
        GoNext();
}

int TDatList::GetCurrentPos() const { //получить номер текущего звена
    return CurrPos;
}

void TDatList::Reset() {//установить на начало списка
    pPrevLink = pStop;
    if(IsEmpty()) {
        pCurrLink = pStop; CurrPos = -1;
    }
    else {
        pCurrLink = pFirst; CurrPos = 0;
    }
}

void TDatList::GoNext() { //Сдвиг вправо текущего звена
    if(pCurrLink == pStop)
        throw ListNoPos;
    pPrevLink = pCurrLink;
    pCurrLink = pCurrLink->GetNextDatLink();
    CurrPos++;
}

int TDatList::IsListEnded() const { // список завершен?
	// (=1 после применения GoNext для последнего звена списка
    return pCurrLink == pStop;
}

void TDatList::InsFirst(PTDatValue pVal) { //вставить перед первым
    PTDatLink tmp = GetLink(pVal, pFirst);
    if(tmp == NULL)
        throw ListNoMem;
    pFirst = tmp;
    ListLen++;
    //проверка пустоты списка перед вставкой
    if(ListLen == 1) {
        pLast = tmp;
        Reset();
    }
    //корректировка текущей позиции - отличие обработки для начала списка
    else if(CurrPos == 0)
        pCurrLink = tmp;
    else
        CurrPos++;
}

void TDatList::InsLast(PTDatValue pVal) { //вставить последним
    PTDatLink tmp = GetLink(pVal, pStop);
    if(tmp == NULL)
        throw ListNoMem;
    if(pLast != NULL)
        pLast->SetNextLink(tmp);
    pLast = tmp;
    ListLen++;
    //проверка пустоты списка перед вставкой
    if(ListLen == 1) {
        pFirst = tmp;
        Reset();
    }
    //корректировка текущей позиции - отличие pCurrLink за концом списка
    if(IsListEnded())
        pCurrLink = tmp;
}

void TDatList::InsCurrent(PTDatValue pVal) { //вставить перед текущим
    if(IsEmpty() || pCurrLink == pFirst)
        InsFirst(pVal);
    else if (IsListEnded())
        InsLast(pVal);
    else {
        PTDatLink tmp = GetLink(pVal, pCurrLink);
        if(tmp == NULL)
            throw ListNoMem;
        pCurrLink = tmp;
        pPrevLink->SetNextLink(tmp);
        ListLen++;
    }
}

//методы удаления звеньев
void TDatList::DelFirst() {
    if(IsEmpty())
        throw ListEmpty;
    PTDatLink tmp = pFirst;
    pFirst = pFirst->GetNextDatLink();
    DelLink(tmp);
    --ListLen;
    if(IsEmpty()){
        pLast = pStop;
        Reset();
    }
    //корректировка текущей позиции - отличие обработки для начала списка
    else if(CurrPos == 0)
        pCurrLink = pFirst;
    else if(CurrPos == 1)
        pPrevLink = pStop;
    if(CurrPos > 0)
        --CurrPos;
}

void TDatList::DelCurrent() { //удалить текущее звено
    if(pCurrLink == pStop)
        throw ListNoPos;
    if(pCurrLink == pFirst)
        DelFirst();
    else {
        PTDatLink tmp = pCurrLink;
        //отработка ситуации удаления последнего звена
		pCurrLink = pCurrLink->GetNextDatLink();
		pPrevLink->SetNextLink(pCurrLink);
        DelLink(tmp);
        --ListLen;
    }
}

void TDatList::DelList() { //удалить весь список
    while(!IsEmpty())
        DelFirst();
    pFirst = pLast = pPrevLink = pCurrLink = pStop;
    CurrPos = -1;
}
