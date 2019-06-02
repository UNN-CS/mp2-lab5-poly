#pragma once
#include "THeadRing.h"
#include "TMonom.h"

class TPolinom :
	public THeadRing
{
public:
	TPolinom(int monoms[][2] = NULL, int km=0);
	TPolinom(TPolinom &q);      //  опирование
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+=(TPolinom &q); // сложение 
	TPolinom & operator=(TPolinom &q); // присваивание 
	friend std::ostream& operator<<(std::ostream &os, TPolinom & q);
};

