#pragma once
#include <iostream>
#include "THeadRing.h"
#include "TMonom.h"
class TPolynom : public THeadRing
{
public:
	TPolynom(int monoms[][2] = NULL, int km = 0);
	TPolynom(/*const*/ TPolynom &q);
	PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
	TPolynom &operator+(TPolynom &q);
	TPolynom &operator=(/*const*/ TPolynom &q);
	int CalculatePolynom(int x, int y, int z);
	friend std::ostream &operator<<(std::ostream &os, TPolynom &q);
	friend std::istream &operator>>(std::istream &is, TPolynom &q);
};