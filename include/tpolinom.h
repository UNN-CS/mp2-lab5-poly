#ifndef __POLINOM_H
#define __POLINOM_H
#include <iostream>
#include"tdatvalue.h"
#include "tmonom.h"
#include "theadring.h"

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = nullptr, int km = 0); // �����������
					 // �������� �� ������� ������������-������
	TPolinom(TPolinom &q);      // ����������� �����������
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+=(TPolinom &q); // �������� ���������
	TPolinom & operator=(TPolinom &q); // ������������
	bool operator==(TPolinom &q);
	friend std::ostream& operator<<(std::ostream &os, TPolinom & q);
};
#endif
