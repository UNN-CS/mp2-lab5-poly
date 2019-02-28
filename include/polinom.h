#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <iostream>
#include "headring.h"
#include "monom.h"

class TPolinom: public THeadRing
{
public:
  TPolinom(int monoms[][2]=nullptr, int km=0);
  TPolinom(TPolinom &q);
  PTMonom GetMonom()
  { return dynamic_cast<PTMonom>(GetDatValue()); }

  TPolinom& operator+=(TPolinom &q);
  TPolinom& operator=(TPolinom &q);

  friend std::ostream& operator<<(std::ostream& output, TPolinom& q);
  friend std::istream& operator>>(std::istream& input, TPolinom& q);
};


#endif


