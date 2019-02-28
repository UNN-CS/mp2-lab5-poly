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

std::ostream& operator<<(std::ostream& output, const TMonom& q)
{
  int index = q.GetIndex();
  int X = index / 100,
      Y = (index % 100) / 10,
      Z = index % 10;

  if(q.GetCoeff() > 0)
    output << '+';

  output << q.GetCoeff();
  if(X != 0)
    output << "X";
    if(X != 1)
      output << "^" << X;
  if(Y != 0)
    output << "Y";
    if(Y != 1)
      output << "^" << Y;
  if(Z != 0)
    output << "Z";
    if(Z != 1)
      output << "^" << Z;

  return output;
}

std::istream& operator>>(std::istream& input, TMonom& q)
{
  int X, Y, Z;

  input >> q.Coeff;
  input >> X;
  input >> Y;
  input >> Z;

  if(   X > 9 || X < 0
     || Y > 9 || Y < 0
     || Z > 9 || Z < 0)
    throw -1;

  q.Index = 100*X + 10*Y + Z;

  return input;
}



