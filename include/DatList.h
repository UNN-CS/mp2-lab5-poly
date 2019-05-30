#ifndef __TDATLIST_H__
#define __TDATLIST_H__

#include "DatLink.h"
#include "DatValue.h"

enum TLinkPos {FIRST, CURRENT, LAST};

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
    PTDatLink GetLink ( PTDatValue pVal=NULL, PTDatLink pLink=NULL );
    void      DelLink ( PTDatLink pLink ); 
  public:
    TDatList();
    ~TDatList() { DelList(); }
    PTDatValue GetDatValue ( TLinkPos mode = CURRENT ) const; 
    virtual int IsEmpty()  const { return pFirst==pStop; }
    int GetListLength() const { return ListLen; } 
    void SetCurrentPos ( int pos );          
    int GetCurrentPos () const;  
    virtual void Reset ();      
    virtual int IsListEnded () const; 
    void GoNext ();
    virtual void InsFirst  ( PTDatValue pVal=NULL );
    virtual void InsLast   ( PTDatValue pVal=NULL );
    virtual void InsCurrent( PTDatValue pVal=NULL );
    virtual void DelFirst  (); 
    virtual void DelCurrent(); 
    virtual void DelList   (); 
};

#endif // __TDATLIST_H__
