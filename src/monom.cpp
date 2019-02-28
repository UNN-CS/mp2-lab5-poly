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

std::ostream& operator<<(std::ostream& output, TMonom& q)
{
  int index = q.GetIndex();
  int X = index / 100,
      Y = (index % 100) / 10,
      Z = index % 10;

  if(q.GetCoeff() > 0)
    output << '+';

  output << q.GetCoeff();
  if(X != 0)
    output << "X^" << X;
  if(Y != 0)
    output << "Y^" << Y;
  if(Z != 0)
    output << "Z^" << Z;

  return output;
}



