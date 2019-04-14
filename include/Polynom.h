#pragma once
#include <iostream>
#include "HeadRing.h"
#include "Monom.h"
class TPolynom : public THeadRing
{
public:
	TPolynom(int monoms[][2] = NULL, int km = 0); // конструктор
												  // полинома из массива «коэффициент-индекс»
	TPolynom(/*const*/ TPolynom &q);                  // конструктор копирования
	PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
	TPolynom &operator+(TPolynom &q);                                  // сложение полиномов
	TPolynom &operator=(/*const*/ TPolynom &q);                                  // присваивание
	int CalculatePolynom(int x, int y, int z);                         //Вычисление значения полинома
	friend std::ostream &operator<<(std::ostream &os, TPolynom &q);
	friend std::istream &operator>>(std::istream &is, TPolynom &q);
};