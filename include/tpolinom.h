#include "tmonom.h"
#include "theadring.h"

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); 
	TPolinom(const TPolinom &q);      
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+(TPolinom &q); 
	TPolinom & operator=(TPolinom &q); 
};
