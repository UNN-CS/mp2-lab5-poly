#include "Monom.h"

TDatValue* TMonom::GetCopy()
{
	PTMonom tmp = new TMonom(this->Coeff, this->Index);
	return tmp;
}