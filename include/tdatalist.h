#include "tdatlink.h"

class TDatList;
typedef TDatList *PTDatList;

enum TLinkPos{FIRST, CURRENT, LAST};

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
	void      DelLink(PTDatLink pLink);   
public:
	TDatList();
	~TDatList() { DelList(); }
	PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; 
	virtual int IsEmpty()  const { return pFirst == pStop; } 
	int GetListLength()    const { return ListLen; }       
	void SetCurrentPos(int pos);          
	int GetCurrentPos(void) const;       
	virtual void Reset(void);             
	virtual int IsListEnded(void) const; 
	void GoNext(void);                    
	virtual void InsFirst(PTDatValue pVal = NULL); 
	virtual void InsLast(PTDatValue pVal = NULL);  
	virtual void InsCurrent(PTDatValue pVal = NULL); 
	virtual void DelFirst(void);    
	virtual void DelCurrent(void);     
	virtual void DelList(void);    
};