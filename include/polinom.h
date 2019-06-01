#include "monom.h"
#include "headring.h"

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор полинома 
												  
	TPolinom(TPolinom &q);      
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+=(TPolinom &q); 
	TPolinom & operator=(TPolinom &q);
	bool operator==(TPolinom &q);
	friend std::ostream& operator<<(std::ostream &os, TPolinom & q); //печать полинома	
};