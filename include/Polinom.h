#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

using namespace std;

typedef TMonom* PTMonom;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = 0, int km = 0); // конструктор
												// полинома из массива «коэффициент-индекс»
	TPolinom(TPolinom &q);      // конструктор копирования
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+=(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание
	bool operator==(TPolinom& q);
	bool operator !=(TPolinom& q);
	friend ostream& operator<<(ostream& out, TPolinom& p);
};
