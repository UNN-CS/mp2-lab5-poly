#ifndef H_POLINOM
#define H_POLINOM

#include "HeadRing.h"
#include "Monom.h"
#include "DatValue.h"

class TPolinom : THeadRing
{

public:
	TPolinom(int monoms[][2] = NULL, int km = 0); 
	TPolinom(const TPolinom &q);    
	TPolinom(TPolinom &q); 
	TPolinom(const TPolinom &q);
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+(TPolinom &q); 
	TPolinom & operator+=(TPolinom &q);
	TPolinom & operator=(TPolinom &q);
	bool operator==(TPolinom &q);
	bool operator!=(TPolinom &q); 
	friend std::ostream& operator<<(std::ostream& out, TPolinom& p);
};

#endif H_POLINOM