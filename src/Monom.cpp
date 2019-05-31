#include "Monom.h"

TDatValue * TMonom::GetCopy() { // изготовить копию
    TMonom * tmp = new TMonom;
    tmp ->Coeff = Coeff, tmp->Index = Index;
    return tmp;
}
