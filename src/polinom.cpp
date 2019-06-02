#include "polinom.h"

TPolinom::TPolinom(int monoms[][2], int km) : THeadRing()
{
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);
	for (int i = 0; i < km; i++)
	{
		tmp = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(tmp);
	}
}

TPolinom::TPolinom(TPolinom &q)
{
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
	}
}

TPolinom& TPolinom::operator+=(TPolinom &q)
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
		else
		{
			if (pm->Index > qm->Index)
				GoNext();
			else
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
	}
	return *this;
}

TPolinom& TPolinom::operator=(TPolinom &q)
{
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
	}
	return *this;
}

bool TPolinom::operator==(TPolinom &q) 
{
	Reset();
	q.Reset();
	while (true) 
	{
		if (IsListEnded() || q.IsListEnded()) 
		{
			if (IsListEnded() && q.IsListEnded())
				return true;
			return false;
		}
		if (*GetMonom() != *q.GetMonom())
			return false;
		GoNext();
		q.GoNext();
	}
}

std::ostream& operator<<(std::ostream& os, TPolinom& q) {
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
		os << "Coeff: " << q.GetMonom()->GetCoeff() << " Index: " << q.GetMonom()->GetIndex() << std::endl;
	return os;
}