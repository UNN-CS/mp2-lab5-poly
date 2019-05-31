// Полиномы

#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

#define PolinomWrongIndex -104

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор из массива «коэффициент-индекс»
					 
	TPolinom(TPolinom &q);      // конструктор копирования
	TPolinom(const TPolinom &q);
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+=(TPolinom &q); // сложение
	TPolinom & operator=(TPolinom &q); // присваивание
	bool operator==(TPolinom &q); 
	bool operator!=(TPolinom &q); 
	friend std::ostream& operator<<(std::ostream& out, TPolinom& p);
};

#endif // __TPOLINOM_H__
