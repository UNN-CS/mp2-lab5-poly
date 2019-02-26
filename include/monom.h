#ifndef __MONOM_H__
#define __MONOM_H__

#include "datvalue.h"

class TMonom: public TDatValue
{
protected:
  int Coeff;
  int Index;
public:
  TMonom(int cval=1, int ival=0)
  {
    if(ival < -1 || ival > 999)
    {
      throw -1;
    }
    Coeff = cval;
    Index = ival;
  }
  virtual TDatValue* GetCopy() const override;
  void SetCoeff(int cval);
  int GetCoeff() const;
  void SetIndex(int ival);
  int GetIndex() const;
  TMonom& operator=(const TMonom &tm)
  {
    Coeff = tm.Coeff;
    Index = tm.Index;
    return *this;
  }
  bool operator==(const TMonom &tm) const
  {
    return Coeff == tm.Coeff && Index == tm.Index;
  }
  bool operator<(const TMonom &tm) const
  {
    return Index < tm.Index;
  }

  friend class TPolinom;
};

#endif

