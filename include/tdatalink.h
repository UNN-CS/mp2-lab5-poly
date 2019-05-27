#ifndef __DATLINK_H
#define __DATLINK_H
#include "trootlink.h"

class TDatLink;
typedef TDatLink *PTDatLink;

class TDatLink : public TRootLink {
protected:
	PTDatValue pValue;  // указатель на объект значения
public:
	TDatLink(PTDatValue pVal = nullptr, PTRootLink pN = nullptr) :
		TRootLink(pN) {
		pValue = pVal;
	}
	void       SetDatValue(PTDatValue pVal) { pValue = pVal; }
	PTDatValue GetDatValue() { return  pValue; }
	PTDatLink  GetNextDatLink() { return  (PTDatLink)pNext; }
	friend class TDatList;
};
#endif
