#ifndef __DATLINK_H__
#define __DATLINK_H__

#include "RootLink.h"

class TDatLink;
typedef TDatLink *PTDatLink;
enum TLinkPos { FIRST, CURRENT, LAST };

class TDatLink : public TRootLink {
protected:
    PTDatValue pValue; 
public:
    TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) :
        TRootLink(pN) {
        pValue = pVal;
    }
    void       SetDatValue(PTDatValue pVal) { pValue = pVal; }
    PTDatValue GetDatValue() { return  pValue; }
    PTDatLink  GetNextDatLink() { return  (PTDatLink)pNext; }
    friend class TDatList;
};

#endif 