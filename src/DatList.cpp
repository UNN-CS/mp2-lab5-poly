#include "DatList.h"

TDatList::TDatList() {
    pFirst = pPrevLink = pCurrLink = pLast = pStop = nullptr;
    CurrPos = -1;
    ListLen = 0;
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink) {
    PTDatLink tmp = new TDatLink(pVal, pLink); // выделение звена
    if (tmp == nullptr)
        throw ListNoMem;
    return tmp;
}

void TDatList::DelLink(PTDatLink pLink) {
    if (pLink != nullptr) {
        if (pLink->pValue != nullptr) delete pLink->pValue;
        delete pLink;
    }
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const {
    PTDatLink tmp;
    switch (mode) {
    case FIRST: tmp = pFirst; break;
    case LAST: tmp = pLast; break;
    default: tmp = pCurrLink; break;
    }
    return (tmp == nullptr) ? nullptr : tmp->pValue;
}

int TDatList::SetCurrentPos(int pos) {
    Reset();
    for (int i = 0; i < pos; ++i, GoNext());
    return ListOK;
}

int TDatList::GetCurrentPos(void) const {
    return CurrPos;
}

int TDatList::Reset(void) {
    pPrevLink = pStop;
    if (IsEmpty()) {
        pCurrLink = pStop;
        CurrPos = -1;
        return ListEmpty;
    }
    else {
        pCurrLink = pFirst;
        CurrPos = 0;
        return ListOK;
    }
}

int TDatList::GoNext(void) {
    if (pCurrLink == pStop)
        throw ListNoPos;
    else {
        pPrevLink = pCurrLink;
        pCurrLink = pCurrLink->GetNextDatLink();
        CurrPos++;
        return ListOK;
    }
}

int TDatList::IsListEnded(void) const {
    return pCurrLink == pStop;
}

void TDatList::InsFirst(PTDatValue pVal) {
    PTDatLink tmp = GetLink(pVal, pFirst);
    if (tmp == nullptr)
        throw ListNoMem;
    else {
        pFirst = tmp;
        ListLen++;
        if (ListLen == 1) {
            pLast = tmp;
            Reset();
        }
        else if (CurrPos == 0)
            pCurrLink = tmp;
        else
            CurrPos++;
    }
}

void TDatList::InsLast(PTDatValue pVal) {
    PTDatLink tmp = GetLink(pVal, pStop);
    if (tmp == nullptr)
        throw ListNoMem;
    else {
        if (pLast != nullptr)
            pLast->SetNextLink(tmp);
        pLast = tmp;
        ListLen++;
        if (ListLen == 1) {
            pFirst = tmp;
            Reset();
        }
        if (IsListEnded())
            pCurrLink = tmp;
    }
}

void TDatList::InsCurrent(PTDatValue pVal) {
    if (IsEmpty() || (pCurrLink == pFirst)) InsFirst(pVal);
    else if (IsListEnded()) InsLast(pVal);
    else if (pPrevLink == pStop)
        throw ListNoPos;
    else {
        PTDatLink tmp = GetLink(pVal, pCurrLink);
        if (tmp == nullptr)
            throw ListNoMem;
        else {
            pCurrLink = tmp;
            pPrevLink->SetNextLink(tmp);
            ListLen++;
        }
    }
}

void TDatList::DelFirst(void) {
    if (IsEmpty())
        throw ListEmpty;
    else {
        PTDatLink tmp = pFirst;
        pFirst = pFirst->GetNextDatLink();
        DelLink(tmp);
        ListLen--;
        if (IsEmpty()) {
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

void TDatList::DelCurrent(void) {
    if (pCurrLink == pStop)
        throw ListNoPos;
    else if (pCurrLink == pFirst) DelFirst();
    else {
        if (pCurrLink == pLast)
            pLast = pPrevLink;
        PTDatLink tmp = pCurrLink;
        pCurrLink = pCurrLink->GetNextDatLink();
        pPrevLink->SetNextLink(pCurrLink);
        DelLink(tmp);
        ListLen--;
    }
}

void TDatList::DelList(void) {
    while (!IsEmpty())
        DelFirst();
    pFirst = pPrevLink = pCurrLink = pLast = pStop;
    CurrPos = -1;
}
