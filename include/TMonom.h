#pragma once
#include "TDatValue.h"
#include<iostream>

using namespace std;
class TMonom :public TDatValue
{
protected:
	int coeff;
	int Index;
public:
	TMonom(int cval = 1, int ival = 0) { coeff = cval, Index = ival; };
	~TMonom();
	virtual TDatValue * GetCopy();
	void SetCoeff(int cval) { coeff = cval; };
	int GetCoeff(void) { return coeff; };
	void SetIndex(int ival) { Index = ival; };
	int GetIndex(void) { return Index; };
	TMonom& operator = (const TMonom &tm) {
		coeff = tm.coeff; 
		Index = tm.Index;
		return *this;
	}
	bool operator==(const TMonom &tm){
		return (coeff == tm.coeff) && (Index == tm.Index);
	};
	bool operator< (const TMonom &tm) { return Index < tm.Index; }

	friend ostream& operator<<(ostream &os, TMonom &tm) {
		os << tm.coeff << " " << tm.Index << " " << endl;
		return os;
	};
	friend class TPolinom;
};
typedef TMonom *PTMonom;
