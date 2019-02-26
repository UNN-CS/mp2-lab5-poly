#include "../include/monom.h"

TDatValue* TMonom::GetCopy() const
{
  return new TMonom(Coeff, Index);
}

void TMonom::SetCoeff(int cval)
{
  Coeff = cval;
}

int TMonom::GetCoeff() const
{
  return Coeff;
}

void TMonom::SetIndex(int ival)
{
  Index = ival;
}

int TMonom::GetIndex() const
{
  return Index;
}



