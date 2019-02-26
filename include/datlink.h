#ifndef __DATLINK_H__
#define __DATLINK_H__

#include "rootlink.h"

class TDatLink;
typedef TDatLink *PTDatLink;

class TDatLink: public TRootLink
{
protected:
  PTDatValue pValue;
public:
  TDatLink(PTDatValue pVal=nullptr, PTRootLink pN=nullptr)
    :TRootLink(pN)
  { pValue = pVal; }

  void SetDatValue(PTDatValue pVal)
  { pValue = pVal; }

  PTDatValue GetDatValue() const
  { return pValue; }

  PTDatLink GetNextLink() const
  { return dynamic_cast<PTDatLink>(pNext); }

  friend class TDatList;
};

#endif

