#include "Monom.h"

TMonom::TMonom(int cval, int ival)
{
    if ((ival < 0 || ival > 999) && (cval != 0)) throw - 1;
    Coeff = cval;
    Index = ival;
}

void TMonom::SetCoeff(int cval)
{
    Coeff = cval;
}

int TMonom::GetCoeff()
{
    return Coeff;
}

void TMonom::SetIndex(int ival)
{
    Index = ival;
}

int TMonom::GetIndex()
{
    return Index;
}

TMonom& TMonom::operator=(const TMonom& tm)
{
    if (this != &tm)
    {
        Coeff = tm.Coeff;
        Index = tm.Index;
    }
    return *this;
}

bool TMonom::operator==(const TMonom& tm)
{
    return (Coeff == tm.Coeff) && (Index == tm.Index);
}

bool TMonom::operator<(const TMonom& tm)
{
    return Index<tm.Index;
}

PTDatValue TMonom::GetCopy()
{
    PTDatValue t = new TMonom(Coeff, Index);
    return t;
}