
#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

#define PolinomWrongIndex -104

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // êîíñòðóêòîð
												  // ïîëèíîìà èç ìàññèâà «êîýôôèöèåíò-èíäåêñ»
	TPolinom(TPolinom &q);      // êîíñòðóêòîð êîïèðîâàíèÿ
	TPolinom(const TPolinom &q);
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+(TPolinom &q);
	TPolinom & operator=(TPolinom &q); // ïðèñâàèâàíèå
	bool operator==(TPolinom &q);
	friend std::ostream& operator<<(std::ostream& out, TPolinom& p);
};

#endif // __TPOLINOM_H__
