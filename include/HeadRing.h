#ifndef __HEADRING_H__
#define __HEADRING_H__

#include "DatList.h"

class THeadRing : public TDatList {
protected:
    PTDatLink pHead;
public:
    THeadRing();
    ~THeadRing();

    virtual void InsFirst(PTDatValue pVal = NULL);
    virtual void DelFirst();
    virtual bool IsEmpty() const;
    virtual void InsCurrent(PTDatValue pVal = NULL);
};

#endif 