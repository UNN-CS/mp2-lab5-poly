#include "tmonom.h"


TDatValue * TMonom::GetCopy()
{
	TDatValue * tmp = new TMonom(Coeff, Index);
	return tmp;
}
