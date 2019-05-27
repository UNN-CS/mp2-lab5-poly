#ifndef __DATLINK_H__
#define __DATLINK_H__

#include "RootLink.h"

class TDatLink : public TRootLink 
{
protected:
	PTDatValue pValue;  // указатель на объект значения
public:
	TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) :
		TRootLink(pN) {
		pValue = pVal;
	}
	void       SetDatValue(PTDatValue pVal) { pValue = pVal; }
	PTDatValue GetDatValue() const
	{ 
		return  pValue; 
	}
	PTDatLink	GetNextDatLink() const 
	{ 
		return	(PTDatLink)pNext; 
	}

	friend class TDatList;
};

typedef TDatLink *PTDatLink;

#endif // __DATLINK_H__
