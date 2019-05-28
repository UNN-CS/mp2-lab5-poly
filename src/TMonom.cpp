#include "TMonom.h"



TDatValue * TMonom::GetCopy()
{
	TDatValue *temp = new TMonom(coeff, Index); 
	return temp;
};
TMonom::~TMonom()
{
}
