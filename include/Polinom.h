#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

class TPolinom : public THeadRing {
public:
    TPolinom(int monoms[][2] = NULL, int km = 0);
    TPolinom(TPolinom &q);
    PTMonom GetMonom();
    TPolinom& operator+=(TPolinom &q);
    TPolinom& operator=(TPolinom &q);
    bool operator==(TPolinom &q);
    bool operator!=(TPolinom &q);
    void Print();
};