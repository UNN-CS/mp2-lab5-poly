#include "HeadRing.h"
#include "Monom.h"

typedef TMonom *PTMonom;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0 ); // конструктор
	TPolinom(TPolinom &q);      // конструктор копирования
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator=(TPolinom &q); // присваивание
	bool	operator==(TPolinom &q);
	TPolinom & operator+=(TPolinom &q);
	void Print();
};
