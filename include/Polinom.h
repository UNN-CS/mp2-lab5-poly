#pragma once
#include "HeadRing.h"
#include "Monom.h"
#include <iostream>
class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор
					 // полинома из массива «коэффициент-индекс»
	TPolinom(TPolinom &poly); // конструктор копирования
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание
	int CalculatePolynom(int x, int y, int z);
	friend std::ostream& operator<<(std::ostream &os, TPolinom &q);
	friend std::istream& operator>>(std::istream &is, TPolinom &q);
};
