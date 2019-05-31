#ifndef __ROOTLINK_H__
#define __ROOTLINK_H__

#include "DatValue.h"

class TRootLink;
typedef TRootLink* PTRootLink;

class TRootLink {
protected:
    PTRootLink pNext;
public:
    TRootLink(PTRootLink pN = NULL);
    PTRootLink GetNextLink();
    void SetNextLink(PTRootLink pLink);
    void InsNextLink(PTRootLink pLink);
    virtual void SetDatValue(PTDatValue pVal) = 0;
    virtual PTDatValue GetDatValue() = 0;

    friend class TDatList;
    friend class THeadRing;
};

#endif 
