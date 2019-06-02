#pragma once
#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

class TPolinom : public THeadRing
{
public:
	TPolinom(int monoms[][2] = nullptr, int km = 0); 		
	TPolinom(const TPolinom &q); 
	PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+(TPolinom &q); 
	TPolinom & operator=(TPolinom &q);
	bool operator==(TPolinom &q);	
};
