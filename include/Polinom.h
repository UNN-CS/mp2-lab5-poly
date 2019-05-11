#ifndef __POLINOM_H
#define __POLINOM_H

#include "Monom.h"
#include "HeadRing.h"

class TPolinom: public THeadRing {
public:
    TPolinom(int monoms[][2] = nullptr, int km = 0); // �����������
    // �������� �� ������� ������������-������
    TPolinom(const TPolinom& q); // ����������� �����������
    PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
    TPolinom& operator+(TPolinom& q); // �������� ���������
    TPolinom& operator=(TPolinom& q); // ������������
};
#endif
