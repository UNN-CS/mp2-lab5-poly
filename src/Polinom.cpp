#include <stdexcept>
#include "Polinom.h"

TPolinom::TPolinom(int monoms[][2], int km)
{
	if (km < 0)
		throw std::invalid_argument("ERROR!! km can't be negative!");
	PTMonom temp = new TMonom(0, -1);
	pHead->SetDatValue(temp);
	for (int i = 0; i < km; i++)
	{
		temp = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(temp);
	}
}

TPolinom::TPolinom(const TPolinom & q)
{
	PTMonom temp = new TMonom(0, -1);
	pHead->SetDatValue(temp);
	PTDatLink tmp2 = q.pFirst;
	for (int i = 0; i < q.ListLen; i++)
	{
		InsLast(tmp2->GetDatValue()->GetCopy());
		tmp2 = tmp2->GetNextDatLink();
	}
}

TPolinom & TPolinom::operator+(TPolinom & q)
{
	TPolinom res(*this);
	res.Reset(); q.Reset();
	for (int i = 0; i < q.ListLen; i++)
	{
		PTMonom mon1 = q.GetMonom();
		while (true)
		{
			PTMonom mon2 = res.GetMonom();
			if (mon1->Index == mon2->Index)
			{
				res.GetMonom()->SetCoeff(mon1->Coeff + mon2->Coeff);
				break;
			}
			if (mon1->Index > mon2->Index)
			{
				res.InsCurrent(mon1->GetCopy());
				break;
			}
			break;
		}
		q.GoNext();
	}
	return res;
}

TPolinom & TPolinom::operator=(TPolinom & q)
{
	if (this != &q)
	{
		DelList();
		PTDatLink tmp = q.pFirst;
		while (tmp != q.pStop)
		{
			PTMonom monom = q.GetMonom();
			InsLast(monom->GetCopy());
			tmp = tmp->GetNextDatLink();
		}
	}
	return *this;
}

bool TPolinom::operator==(TPolinom & q)
{
	Reset();
	q.Reset();
	if (this->GetListLength() == q.GetListLength())
	{
		for (Reset(), q.Reset(); !IsListEnded(); q.GoNext(), GoNext())
		{

			if (*GetMonom() != *q.GetMonom())
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
