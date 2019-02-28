#ifndef __HEADRING_H__
#define __HEADRING_H__

#include "datlist.h"

class THeadRing: public TDatList
{
protected:
  PTDatLink pHead;
public:
  THeadRing();
  virtual ~THeadRing();

  virtual void InsFirst(PTDatValue pVal=nullptr) override;
  virtual void DelFirst() override;
};

#endif

