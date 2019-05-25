#ifndef __TROOTLINK_H__
#define __TROOTLINK_H__

#include <iostream>

#include "DatValue.h"

class TRootLink;
typedef TRootLink *PTRootLink;

class TRootLink 
{
protected:
	PTRootLink  pNext;  // указатель на следующее звено
public:
	TRootLink(PTRootLink pN = NULL) { pNext = pN; }
	PTRootLink  GetNextLink() { return  pNext; }
	void SetNextLink(PTRootLink  pLink) { pNext = pLink; }
	void InsNextLink(PTRootLink  pLink) {
		PTRootLink p = pNext;  pNext = pLink;
		if (pLink != NULL) pLink->pNext = p;
	}
	virtual void       SetDatValue(PTDatValue pVal) = 0;
	virtual PTDatValue GetDatValue() = 0;

	friend class TDatList;
};

#endif // __TROOTLINK_H__