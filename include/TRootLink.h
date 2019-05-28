#pragma once
#include <iostream>
#include "TDatValue.h"

class TRootLink;
typedef TRootLink *pTRootLink;

class TRootLink {
protected:
	pTRootLink  pNext;  
public:
	TRootLink(pTRootLink pN = NULL) { pNext = pN; }
	pTRootLink  GetNextLink() { return  pNext; }
	void SetNextLink(pTRootLink  pLink) { pNext = pLink; }
	void InsNextLink(pTRootLink  pLink) {
		pTRootLink p = pNext;  pNext = pLink;
		if (pLink != NULL) pLink->pNext = p;
	}
	virtual void       SetDatValue(PTDatValue pVal) = 0;
	virtual PTDatValue GetDatValue() = 0;

	friend class TDatList;
};
