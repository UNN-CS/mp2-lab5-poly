#include <iostream>
#include "Monom.h"
#include "HeadRing.h" 

class TPolinom : public THeadRing {
  public:
    TPolinom ( int monoms[][2]=NULL, int km=0 ); // �����������
	TPolinom(TPolinom &q); // �������� �� ������� ������������-������
    TPolinom ( const TPolinom &q);      // ����������� �����������
    PTMonom  GetMonom()  { return (PTMonom)GetDatValue(); }
    TPolinom & operator+( TPolinom &q); // �������� ���������
    TPolinom & operator=( TPolinom &q); // ������������
	friend std::ostream& operator<<(std::ostream& out, TPolinom& p);
};
