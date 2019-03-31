﻿#ifndef __MONOM_H__
#define __MONOM_H__

#include <iostream>
#include "TDatValue.h"

class TMonom : public TDatValue {
protected:
	int Coeff; // êîýôôèöèåíò ìîíîìà
	int Index; // èíäåêñ (ñâåðòêà ñòåïåíåé)
public:
	TMonom(int cval = 1, int ival = 0) {
		Coeff = cval; Index = ival;
	}
	virtual TDatValue * GetCopy(); // èçãîòîâèòü êîïèþ
	void SetCoeff(int cval) { Coeff = cval; }
	int  GetCoeff() { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int  GetIndex() { return Index; }
	TMonom& operator=(const TMonom &tm) {
		Coeff = tm.Coeff; Index = tm.Index;
		return *this;
	}
	int operator==(const TMonom &tm) {
		return (Coeff == tm.Coeff) && (Index == tm.Index);
	}
	int operator<(const TMonom &tm) {
		return Index<tm.Index;
	}
	friend class TPolinom;
};

typedef TMonom* PTMonom;
#endif // __MONOM_H__