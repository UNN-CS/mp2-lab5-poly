#include "Monom.h"

TDatValue * TMonom::GetCopy()
{
	TMonom * tmp = new TMonom;
	tmp->Coeff = Coeff;
	tmp->Index = Index;
	return tmp;
}