#pragma once
#include "TDatList.h"
#include "TDatLink.h"
#include "TDatValue.h"
class THeadRing : public TDatList
{
protected:
	PTDatLink pHead;
public:
	THeadRing();
	~THeadRing();
	virtual void InsFirst(PTDatValue pVal = NULL);
	virtual void DelFirst(void);
};
