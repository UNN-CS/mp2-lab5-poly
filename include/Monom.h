#pragma once
#include "DatValue.h"

class TMonom;
typedef TMonom *PTMonom;
class TMonom : public TDatValue 
{
protected:
	int Coeff; 
	int Index; 
public:
	TMonom(int cval = 1, int ival = 0);
	virtual TDatValue * GetCopy(); 
	void SetCoeff(int cval);
	int GetCoeff(void);
	void SetIndex(int ival);
	int GetIndex(void);
	TMonom& operator=(const TMonom &tm);
	bool operator==(const TMonom &tm);
	bool operator!=(const TMonom &tm);
	bool operator<(const TMonom &tm);
	friend class TPolinom;
};
