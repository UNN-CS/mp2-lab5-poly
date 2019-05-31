#ifndef __MONOM_H__
#define __MONOM_H__

#include "DatValue.h"

class TMonom;
typedef TMonom* PTMonom;

class TMonom : public TDatValue {
protected:
    int Coeff;
    int Index;
public:
    TMonom(int cval = 1, int ival = 0);
    virtual TDatValue* GetCopy();
    void SetCoeff(int cval);
    int GetCoeff();
    void SetIndex(int ival);
    int GetIndex();
    TMonom& operator=(const TMonom& tm);
    bool operator==(const TMonom& tm);
    bool operator<(const TMonom& tm);

    friend class TPolinom;
};

#endif 