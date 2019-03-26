#include "Monom.h"

using namespace std;

TDatValue *TMonom :: GetCopy()
	{
		TDatValue * temp = new TMonom(Coeff, Index);
		return temp;
	}

void TMonom::Print()
{
	cout << Coeff << " " << Index << endl;
}