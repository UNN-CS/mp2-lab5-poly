#include "Monom.h"

TMonom::TMonom(int cval, int ival)
{
	Coeff = cval;
	Index = ival;
}

TDatValue* TMonom::GetCopy()
{
	TMonom* tmp = new TMonom(this->Coeff, this->Index);
	return tmp;
}

void TMonom::SetCoeff(int cval)
{
	Coeff = cval;
}

int TMonom::GetCoeff(void)
{
	return Coeff;
}

void TMonom::SetIndex(int ival)
{
	Index = ival;
}

int TMonom::GetIndex(void)
{
	return Index;
}

TMonom& TMonom::operator=(const TMonom &tm)
{
	Coeff = tm.Coeff;
	Index = tm.Index;
	return *this;
}

bool TMonom::operator==(const TMonom &tm)
{
	return (Coeff == tm.Coeff) && (Index == tm.Index);
}

bool TMonom::operator!=(const TMonom &tm)
{
	return (Coeff != tm.Coeff) || (Index != tm.Index);
}

bool TMonom::operator<(const TMonom &tm)
{
	return Index< tm.Index;
}
