#pragma once
#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

class TPolinom : public THeadRing 
{
	public:
		TPolinom(int monoms[][2] = NULL, int km = 0); 
		
		TPolinom(TPolinom &q);   
		
		PTMonom GetMonom() 
		{
			return (PTMonom)GetDatValue();
		}
		
		TPolinom & operator+(TPolinom &q);
		
		TPolinom & operator=(TPolinom &q); 
		
		int CalculatePolynom(int x, int y, int z);
		
		friend std::ostream& operator<<(std::ostream &os, TPolinom &q);
		
		friend std::istream& operator>>(std::istream &is, TPolinom &q);
};