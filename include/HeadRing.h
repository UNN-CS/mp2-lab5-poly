#pragma once
#include "DatList.h"

class THeadRing : public TDatList 
{
protected:
	PTDatLink pHead; 
public:
	THeadRing();
	~THeadRing();	
	virtual void InsFirst(PTDatValue pVal = nullptr); 													  
	virtual void DelFirst(void); 
};
