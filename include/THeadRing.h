#pragma once
#include "TDatList.h"
class THeadRing :
	public TDatList
{
protected:
	PTDatLink pHead;

public:
	THeadRing();
	~THeadRing();
   // Вставка звеньев
	virtual void InsFirst(PTDatValue pVal = nullptr);
	// delete 
	virtual void DelFirst(void);
};

