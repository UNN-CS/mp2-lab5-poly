#include "Monom.h"

TDatValue* TMonom::GetCopy()
{
	TMonom * t = new TMonom;
	t->Coeff = Coeff;
	t->Index = Index;
	return t;
};