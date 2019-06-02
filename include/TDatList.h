#pragma once
#include "TDatLink.h"


enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList {
  protected:
	PTDatLink pFirst; 
	PTDatLink pLast; 
	PTDatLink pCurrLink; 
	PTDatLink pPrevLink; 
	PTDatLink pStop; 
	int CurrPos; 
	int ListLen; 
  protected: 
	PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL);
	void TDelLink(PTDatLink pLink); 
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

	virtual void InsFirst(PTDatValue pVal = nullptr); 
	virtual void InsLast(PTDatValue pVal = nullptr); 
	virtual void InsCurrent(PTDatValue pVal = nullptr); 
	int GoNext(void);
	virtual void DelFirst(void); 
	virtual void DelCurrent(void); 
	virtual void DelList(void); 
};

typedef TDatList* PTDatList;

