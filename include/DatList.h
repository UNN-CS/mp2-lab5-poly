#pragma once
#include "DatLink.h"

enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList : public TDatLink
{
protected:
	PTDatLink pFirst; 
	PTDatLink pLast; 
	PTDatLink pCurrLink; 
	PTDatLink pPrevLink; 
	PTDatLink pStop; 
	int CurrPos; 
	int ListLen; 
protected: 
	PTDatLink GetLink(PTDatValue pVal = nullptr, PTDatLink pLink = nullptr);
	void DelLink(PTDatLink pLink); 
public:
	TDatList();
	~TDatList() { DelList(); }	
	PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; 
	virtual int IsEmpty() const { return pFirst == pStop; } 
	int GetListLength() const { return ListLen; } 												 
	int SetCurrentPos(int pos);
	int GetCurrentPos(void) const; 
	virtual int Reset(void);
	virtual int IsListEnded(void) const; 
	int GoNext(void);  					 
	virtual void InsFirst(PTDatValue pVal = nullptr);
	virtual void InsLast(PTDatValue pVal = nullptr);
	virtual void InsCurrent(PTDatValue pVal = nullptr);														
	virtual void DelFirst(void); 
	virtual void DelCurrent(void); 
	virtual void DelList(void); 
};
