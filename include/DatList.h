#ifndef __DATLIST_H__
#define __DATLIST_H__

#include "DatLink.h"

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
    virtual bool IsEmpty() const { return pFirst == pStop; };
    int GetListLength()    const { return ListLen; }       

    int SetCurrentPos(int pos);          
    int GetCurrentPos(void) const;       
    virtual int Reset(void);             
    virtual int IsListEnded(void) const; 
    int GoNext(void);                    

    virtual void InsFirst(PTDatValue pVal = NULL); 
    virtual void InsLast(PTDatValue pVal = NULL); 
    virtual void InsCurrent(PTDatValue pVal = NULL); 
                                   
    virtual void DelFirst(void);   
    virtual void DelCurrent(void); 
    virtual void DelList(void);    
};

#endif 