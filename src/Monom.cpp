#include <Monom.h>

TDatValue* TMonom::GetCopy()
{
	return new TMonom(Coeff, Index);
}