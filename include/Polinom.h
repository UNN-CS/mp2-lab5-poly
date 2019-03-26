#include "HeadRing.h"
#include "Monom.h"

typedef TMonom *PTMonom;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0 ); // �����������
	TPolinom(TPolinom &q);      // ����������� �����������
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator=(TPolinom &q); // ������������
	bool	operator==(TPolinom &q);
	TPolinom & operator+=(TPolinom &q);
	void Print();
};
