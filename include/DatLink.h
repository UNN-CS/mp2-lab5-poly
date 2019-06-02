#pragma once
#include "RootLink.h"

class TDatLink;
typedef TDatLink *PTDatLink;

class TDatLink : public TRootLink
{
protected:
	PTDatValue pValue;
public:
	TDatLink(PTDatValue pVal = nullptr, PTRootLink pN = nullptr) :TRootLink(pN) { pValue = pVal; }
	void SetDatValue(PTDatValue pVal);
	PTDatValue GetDatValue();
	PTDatLink GetNextDatLink();
	~TDatLink() { pValue = nullptr; }
	friend class TDatList;
};
