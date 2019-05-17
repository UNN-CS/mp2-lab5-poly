#include "Monom.h"

TDatValue* TMonom::GetCopy() {
    TDatValue* tmp = new TMonom(this->Coeff, this->Index);
    return tmp;
}
