#include <cmath>
#include <string>
#include "Polynom.h"
#include "Monom.h"


TPolynom::TPolynom(int monoms[][2], int km)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	for (int i = 0; i < km; i++)
	{
		if (monoms[i][1] > 999 || monoms[i][1] < 0)
			throw "wrong value";
		pMonom = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(pMonom);
	}
}


TPolynom::TPolynom(/*const*/ TPolynom &q)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy()); //delete Pmonom
	}
}


TPolynom &TPolynom::operator=(TPolynom &q)
{
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
	return *this;
}


TPolynom &TPolynom::operator+(TPolynom &q)
{
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (true)
	{
		pm = GetMonom();
		qm = q.GetMonom();
		if (pm->Index < qm->Index)
		{ //ìîíîì pm ìëàäøå ìîíîìà qm => äîáàâëåíèå ìîíîìà qm â ïîëèíîì p
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm);
			q.GoNext();
		}
		else if (pm->Index > qm->Index)
			GoNext();
		else // èíäåêñû ìîíîìîâ ðàâíû
		{
			if (pm->Index == -1)
				break;
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


std::ostream &operator<<(std::ostream &os, TPolynom &q)
{
	int k = 1;
	for (q.Reset(); !q.IsListEnded(); q.GoNext(), k++)
	{
		if (!(k == 1))
			std::cout << " +" << *q.GetMonom();
		else
			std::cout << *q.GetMonom();
	}
	return os;
}


std::istream &operator>>(std::istream &is, TPolynom &q)
{
	int coeff = 0;
	int amountOfMonom = 0;
	std::string indexStr;
	if (q.ListLen != 0)
		q.DelList();
	std::cout << "write the count of monoms : ";
	is >> amountOfMonom;
	for (q.Reset(); q.CurrPos < amountOfMonom; q.GoNext())
	{
		std::cout << "write coef : ";
		is >> coeff;
		if (coeff == 0)
			continue;
		std::cout << "write the convolution of degrees(x,y,z)"
			<< std::endl
			<< "(3-digit number, in a row without razdiliteley : ";
		is >> indexStr;
		if (indexStr.length() > 3)
			throw "wrong index";
		for (int i = 0; i < indexStr.length(); i++)
		{
			if (isdigit(indexStr[i]) == 0)
				throw "wrong index";
		}

		PTMonom temp = new TMonom(coeff, atoi(indexStr.c_str()));
		q.InsLast(temp);
	}
	return is;
}


int TPolynom::CalculatePolynom(int x, int y, int z)
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