#ifndef __POLINOM_H__
#define __POLINOM_H__
#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

using namespace std;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = nullptr, int km = 0); // êîíñòðóêòîð
												  // ïîëèíîìà èç ìàññèâà «êîýôôèöèåíò-èíäåêñ»
	TPolinom(const TPolinom &q);      // êîíñòðóêòîð êîïèðîâàíèÿ
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom& operator+(TPolinom &q); // ñëîæåíèå ïîëèíîìîâ
	TPolinom& operator=(TPolinom &q); // ïðèñâàèâàíèå
	TPolinom& operator+=(TPolinom &q); // сложение полиномов с присваиванием
	
	friend ostream& operator<<(ostream &out, TPolinom &p);
};

#endif
