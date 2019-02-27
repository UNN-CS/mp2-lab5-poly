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

  virtual ~TDatLink(){}

  virtual void SetDatValue(PTDatValue pVal) override
  { pValue = pVal; }

  virtual PTDatValue GetDatValue() override
  { return pValue; }

  PTDatLink GetNextDatLink() const
  { return dynamic_cast<PTDatLink>(pNext); }

  friend class TDatList;
};

#endif

