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
  int index = q.GetIndex(),
      coeff = q.GetCoeff();
  int X = index / 100,
      Y = (index % 100) / 10,
      Z = index % 10;


  if(coeff == 0)
  {
    output << 0;
  }
  if(index == 0)
  {
    output << std::showpos << coeff << std::noshowpos;
  }
  else
  {
    if(coeff == 1)
      output << '+';
    else if(coeff == -1)
      output << '-';
    else
      output << std::showpos << coeff << '*' << std::noshowpos;

    if(X != 0)
    {
      output << "X";
      if(X != 1)
        output << "^" << X;
    }
    if(Y != 0)
    {
      output << "Y";
      if(Y != 1)
        output << "^" << Y;
    }
    if(Z != 0)
    {
      output << "Z";
      if(Z != 1)
        output << "^" << Z;
    }
  }

  return output;
}

std::istream& operator>>(std::istream& input, TMonom& q)
{
  int ival, cval;

  input >> cval;
  input >> ival;

  if(ival == -1)
  {
    q.Index = -1;
    q.Coeff = 0;
  }
  else if(ival <= 999 && ival >= 0)
  {
    q.Index = ival;
    q.Coeff = cval;
  }
  else
  {
    throw -1;
  }

  return input;
}



