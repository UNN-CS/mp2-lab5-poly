#include "HeadRing.h"

THeadRing::THeadRing() {
	InsLast();
	pHead = pFirst;
	ListLen = 0;
	pStop = pHead;
	Reset();
	pFirst->SetNextLink(pFirst);
}

THeadRing::~THeadRing() {
	TDatList::DelList();
	DelLink(pHead);
	pHead = NULL;
}

void THeadRing::InsFirst(PTDatValue pVal) { //вставить после загловка
	TDatList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst() { //удалить первое звено
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}
