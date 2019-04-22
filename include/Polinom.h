#pragma once
#include "HeadRing.h"
#include "Monom.h"
#include <iostream>
class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор
					 // полинома из массива «коэффициент-индекс»
	TPolinom(const TPolinom &q);      // конструктор копирования
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание
};
