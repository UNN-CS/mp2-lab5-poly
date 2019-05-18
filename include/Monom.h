#pragma once
#include <iostream>
#include "DatValue.h"

class TMonom;
typedef TMonom * PTMonom;

class TMonom : public TDatValue
{
protected:
	int Coeff;
	int Index;
public:
	TMonom(int cval = 1, int ival = 0)
	{
		Coeff = cval;
		Index = ival;
	};
	virtual TDatValue * GetCopy()
	{
		PTDatValue temp = new TMonom(Coeff, Index);
		return temp;
	}
	void SetCoeff(int cval) { Coeff = cval; }
	int  GetCoeff(void) { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int  GetIndex(void) { return Index; }
	TMonom& operator=(const TMonom &tm)
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
	friend std::ostream& operator<<(std::ostream &os, TMonom &mon)
	{
		int indexX = mon.Index / 100;
		int indexY = (mon.Index / 10) % 10;
		int indexZ = mon.Index % 10;

		if (mon.Coeff != 0)
		{
			if (mon.Coeff > 0)
				os << " +" << mon.Coeff << "*";
			else
				os << " " << mon.Coeff << "*";

			if (indexX != 0)
				os << "x^" << indexX;
			if (indexY != 0)
				os << "y^" << indexY;
			if (indexZ != 0)
				os << "z^" << indexZ;
		}

		return os;
	}
	friend class TPolinom;

};