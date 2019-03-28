#include <iostream>
#include "DatValue.h"

class TMonom : public TDatValue {
protected:
	int Coeff; // ����������� ������
	int Index; // ������ (������� ��������)
public:
	TMonom(int cval = 1, int ival = 0)
	{
		Coeff = cval; Index = ival;
	};
	virtual TDatValue * GetCopy(); // ���������� �����
	void SetCoeff(int cval) { Coeff = cval; }
	int  GetCoeff(void) { return Coeff; }
	void SetIndex(int ival) { Index = ival; }
	int  GetIndex(void) { return Index; }
	TMonom& operator=(const TMonom &tm) {
		Coeff = tm.Coeff; Index = tm.Index;
		return *this;
	}
	int operator==(const TMonom &tm) {
		return (Coeff == tm.Coeff) && (Index == tm.Index);
	}
	int operator<(const TMonom &tm) {
		return Index < tm.Index;
	}
	friend class TPolinom;
};
