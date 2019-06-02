#include "Polinom.h"
#include <string>
#include <cmath>


TPolinom::TPolinom(int monoms[][2], int km)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);

	for (int i = 0; i < km; i++)
	{
		pMonom = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(pMonom);
	}
}
/*---------------------------------------------------------------------------*/
TPolinom::TPolinom(TPolinom &poly)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);

	for (poly.Reset(); !poly.IsListEnded(); poly.GoNext())
	{
		PTMonom pMonom = poly.GetMonom();
		InsLast(pMonom->GetCopy());
	}
}
/*---------------------------------------------------------------------------*/
TPolinom& TPolinom::operator+(TPolinom &q)
{
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (true)
	{
		pm = GetMonom();
		qm = q.GetMonom();
		
		if (pm->Index < qm->Index)
		{
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm);
			q.GoNext();
		}
		else if (pm->Index > qm->Index)
			GoNext();
		else
		{
			if (pm->Index == -1) break;
			pm->Coeff += qm->Coeff;

			if (pm->Coeff != 0)
			{
				GoNext();
				q.GoNext();
			}

			else
			{
				DelCurrent();
				q.GoNext();
			}
		}
	}
	return *this;
}
/*---------------------------------------------------------------------------*/
TPolinom& TPolinom::operator = (TPolinom &q)
{
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
	return *this;
}
/*---------------------------------------------------------------------------*/
std::ostream& operator<<(std::ostream &os, TPolinom &q)
{
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
		std::cout << *q.GetMonom();
	std::cout << std::endl;
	return os;
}
/*---------------------------------------------------------------------------*/
std::istream& operator>>(std::istream &is, TPolinom &q)
{
	int coeff;
	int count_of_monoms = 0;
	std::string power_index;

	if (!q.list_len != 0)
		q.DelList();

	std::cout << "Input count of monoms: ";
	std::cin >> count_of_monoms;

	for (q.Reset(); q.curr_pos < count_of_monoms; q.GoNext())
	{
		std::cout << "Input coeff: ";
		is >> coeff;

		std::cout << "Input power(x,y,z)(without spaces): ";
		is >> power_index;

		if (power_index.length() > 3)
			throw "ex";

		if (coeff == 0 
			|| isdigit(power_index[0]) == 0
			|| isdigit(power_index[1]) == 0 
			|| isdigit(power_index[2]) == 0)
			continue;

		PTMonom pMonom = new TMonom(coeff, atoi(power_index.c_str()));
		q.InsLast(pMonom);
	}

	return is;
}

int TPolinom::CalculatePolynom(int x, int y, int z)
{
	int result = 0;
	int indexX;
	int indexY;
	int indexZ;

	for (Reset(); !IsListEnded(); GoNext())
	{
		indexX = GetMonom()->Index / 100;
		indexY = (GetMonom()->Index / 10) % 10;
		indexZ = GetMonom()->Index % 10;
		result += GetMonom()->Coeff * std::pow(x, indexX) * std::pow(y, indexY) * std::pow(z, indexZ);
	}

	return result;
}