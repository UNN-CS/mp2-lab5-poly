#ifndef __DATLINK_H__
#define __DATLINK_H__

#include "TDatValue.h"
#include "RootLink.h"

#include <iostream>

class TDatLink;
typedef TDatLink *PTDatLink;

class TDatLink : public TRootLink {
protected:
	PTDatValue pValue;  // óêàçàòåëü íà îáúåêò çíà÷åíèÿ
public:
	TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) : TRootLink(pN) {
		pValue = pVal;
	}
	void       SetDatValue(PTDatValue pVal) { pValue = pVal; }
	PTDatValue GetDatValue() { return  pValue; }
	PTDatLink  GetNextDatLink() { return  (PTDatLink)pNext; }
	friend class TDatList;
};

#endif // __DATLINK_H__