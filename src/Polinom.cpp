#include "Polinom.h"


TPolinom::TPolinom(int monoms[][2], int km)
{
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);
	for(int i = 0; i < km; i++) 
	{
		if (monoms[i][1] < 0 || monoms[i][1] > 999) { throw - 1; }
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

TPolinom & TPolinom::operator+=(TPolinom &q)
{
	PTMonom m, qm, tm;
	Reset();
	q.Reset();
	while (1)
	{
		m = GetMonom();
		qm = q.GetMonom();
		if (m->Index < qm->Index)
		{
			tm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(tm);
			q.GoNext();
		}
		else if (m->Index > qm->Index)
			GoNext();
		else
		{
			if (m->Index == -1)
				break;
			m->Coeff += qm->Coeff;
			if (m->Coeff != 0)
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

bool TPolinom::operator==(TPolinom &q)
{
	PTMonom m, qm;
	Reset();
	q.Reset();
	while (true)
	{
		m = GetMonom();
		qm = q.GetMonom();
		if (m->Index != qm->Index) 
			return false;
		if (m->Coeff != qm->Coeff) 
			return false;
		if (m->Coeff != 0 && qm->Coeff == 0 ||
			m->Coeff == 0 && qm->Coeff != 0)
			return false;
		else {
			if (m->Coeff == 0 && qm->Coeff == 0)
				return true;
			GoNext();
			q.GoNext();
		}
	}
}
	
TPolinom & TPolinom::operator=(TPolinom &q) // присваивание
{
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, TPolinom & p)
{
	if (p.IsEmpty())
		std::cout << 0;
	for (p.Reset(); !p.IsListEnded(); p.GoNext())
	{
		PTMonom m = p.GetMonom();
		std::cout << "(" << m->GetCoeff() << ", " << m->GetIndex() << ") ";
	}
	return out;
}