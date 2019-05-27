#ifndef __THEADRING_H__
#define __THEADRING_H__
#include "DatList.h"

class THeadRing : public TDatList 
{
protected:
	PTDatLink pHead;     
public:
	THeadRing();
	~THeadRing();
	virtual void InsFirst(PTDatValue pVal = nullptr);
	virtual void DelFirst();            
};

#endif __THEADRING_H__