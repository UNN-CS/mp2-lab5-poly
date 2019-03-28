#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

using namespace std;

typedef TMonom* PTMonom;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = 0, int km = 0); // �����������
												// �������� �� ������� ������������-������
	TPolinom(TPolinom &q);      // ����������� �����������
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+=(TPolinom &q); // �������� ���������
	TPolinom & operator=(TPolinom &q); // ������������
	bool operator==(TPolinom& q);
	bool operator !=(TPolinom& q);
	friend ostream& operator<<(ostream& out, TPolinom& p);
};
