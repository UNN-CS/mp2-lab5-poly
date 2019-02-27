#ifndef __DATLIST_H__
#define __DATLIST_H__

#include "datacom.h"
#include "datlink.h"

#define ListOK 0
#define ListEmpty -101
#define ListNoMem -102
#define ListNoPos -103

enum TLinkPos {FIRST, CURRENT, LAST};

class TDatList: public TDataCom
{
protected:
  PTDatLink pStop;
  PTDatLink pFirst;
  PTDatLink pLast;
  PTDatLink pCurrLink;
  PTDatLink pPrevLink;
  int CurrPos;
  int ListLen;

  PTDatLink GetLink(PTDatValue pVal=nullptr, PTDatLink pLink=nullptr) const;
  void      DelLink(PTDatLink pLink);
public:
  TDatList();
  ~TDatList()
  { DelList(); }

  PTDatValue GetDatValue(TLinkPos mode = CURRENT);

  virtual bool IsEmpty() const
  { return pFirst == pStop; }

  int GetListLength() const
  { return ListLen; }

  int SetCurrentPos(int pos);
  int GetCurrentPos() const;

  virtual int Reset();
  virtual bool IsListEnded() const;
  int GoNext();

  virtual void InsFirst  (PTDatValue pVal=nullptr);
  virtual void InsLast   (PTDatValue pVal=nullptr);
  virtual void InsCurrent(PTDatValue pVal=nullptr);

  virtual void DelFirst();
  virtual void DelCurrent();
  virtual void DelList();

};

#endif

