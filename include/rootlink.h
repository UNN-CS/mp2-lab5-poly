#ifndef __ROOTLINK_H__
#define __ROOTLINK_H__

#include "datvalue.h"

class TRootLink;
typedef TRootLink *PTRootLink;

class TRootLink
{
protected:
  PTRootLink pNext;
public:
  TRootLink(PTRootLink pN = nullptr)
  { pNext = pN; }

  virtual PTRootLink GetNextLink() const
  { return pNext; }

  void SetNextLink(PTRootLink pN)
  { pNext = pN; }

  void InsNextLink(PTRootLink pN)
  {
    if(pN != nullptr)
      pN->pNext = pNext;
    pNext = pN;
  }

  virtual void       SetDatValue(PTDatValue pVal)=0;
  virtual PTDatValue GetDatValue() const=0;

  friend class TDatList;
};

#endif

