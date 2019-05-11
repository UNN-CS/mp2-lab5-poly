#ifndef __POLINOM_H
#define __POLINOM_H

#include "Monom.h"
#include "HeadRing.h"

class TPolinom: public THeadRing {
public:
    TPolinom(int monoms[][2] = nullptr, int km = 0); // конструктор
    // полинома из массива «коэффициент-индекс»
    TPolinom(const TPolinom& q); // конструктор копирования
    PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
    TPolinom& operator+(TPolinom& q); // сложение полиномов
    TPolinom& operator=(TPolinom& q); // присваивание
};
#endif
