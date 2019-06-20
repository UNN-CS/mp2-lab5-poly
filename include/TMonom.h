#pragma once
#include <iostream>
#include "TDatValue.h"
class TMonom;
typedef TMonom *PTMonom;
class TMonom : public TDatValue
{
public:
	float Coeff;
	int Index;
	//------------------------------------
	TMonom(float cval = 1, int ival = 0)
	{
		Coeff = cval;
		Index = ival;
	};
	virtual TDatValue *GetCopy()
	{
		TDatValue *temp = new TMonom(Coeff, Index);
		return temp;
	}
	void SetCoeff(int cval) { Coeff = cval; }
	int GetCoeff(void) { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int GetIndex(void) { return Index; }
	TMonom &operator=(const TMonom &tm)
	{
		Coeff = tm.Coeff;
		Index = tm.Index;
		return *this;
	}
	int operator==(const TMonom &tm)
	{
		return (Coeff == tm.Coeff) && (Index == tm.Index);
	}
	int operator<(const TMonom &tm)
	{
		return Index < tm.Index;
	}
	friend std::ostream &operator<<(std::ostream &os, TMonom &q)
	{
		int powX = q.Index / 100;
		int powY = (q.Index / 10) % 10;
		int powZ = q.Index % 10;
		if (q.Coeff != 0)
		{
			os << " " << q.Coeff;
			if (powX != 0)
				os << "X^" << powX;
			if (powY != 0)
				os << "Y^" << powY;
			if (powZ != 0)
				os << "Z^" << powZ;
		}
		return os;
	}
	friend class TPolinom;
};
