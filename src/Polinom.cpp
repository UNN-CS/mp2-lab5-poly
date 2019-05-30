#include "Polinom.h"
#include <stdexcept> 

TPolinom::TPolinom(int monoms[][2], int km)
{
	if (km < 0)
		throw std::invalid_argument("Negative amount of monoms!");
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);
	for (int i = 0; i<km; i++)
	{
		tmp = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(tmp);
	}
}

TPolinom::TPolinom(const TPolinom &q)
{
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);
	PTDatLink tL = q.pFirst;
	while (tL != q.pStop)
	{
		this->InsLast(tL->GetDatValue()->GetCopy());
		tL = tL->GetNextDatLink();
	}
}

TPolinom& TPolinom::operator+(TPolinom &q)
{
	TPolinom res(*this);
	res.Reset(); 
	q.Reset();
	while (true)
	{
		PTMonom mon1 = res.GetMonom();
		PTMonom mon2 = q.GetMonom();
		if (*mon2 < *mon1)
		{
			res.GoNext();

		}
		else if (*mon1 < *mon2)
		{
			res.InsCurrent(mon2->GetCopy());
			q.GoNext();
		}
		else 
		{
			if (mon1->GetIndex() == -1) break;
			int resCoeff = mon1->GetCoeff() + mon2->GetCoeff();
			if (resCoeff == 0)
			{
				res.DelCurrent();
				q.GoNext();
			}
			else
			{
				mon1->SetCoeff(resCoeff);
				res.GoNext(); q.GoNext();
			}
		}
	}
	return *this;
}

TPolinom& TPolinom::operator=(TPolinom &q)
{
	if (this != &q)
	{
		this->DelList();
		PTDatLink tL = q.pFirst;
		while (tL != q.pStop)
		{
			this->InsLast(tL->GetDatValue()->GetCopy());
			tL = tL->GetNextDatLink();
		}
	}
	return *this;
}

TPolinom& TPolinom::operator+=(TPolinom& q)
{
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (1)
	{
		pm = GetMonom();
		qm = q.GetMonom();
		if (pm->Index < qm->Index)
		{
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm); q.GoNext();
		}
		else if (pm->Index > qm->Index)
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
	return *this;
}

ostream& operator<<(ostream &out, TPolinom &p)
{
	if (p.IsEmpty())
		out << 0;
	else
	{
		PTDatLink tL = p.pFirst;
		PTMonom tm;
		int curCoeff, curIndex, xPow, yPow, zPow;
		while (tL != p.pStop)
		{
			tm = (PTMonom)tL->GetDatValue();
			curIndex = tm->GetIndex();
			curCoeff = tm->GetCoeff();
			xPow = curIndex / 100;
			yPow = curIndex % 100 / 10;
			zPow = curIndex % 10;
			
			if (curCoeff < 0 || tL == p.pFirst)
				cout << curCoeff;
			else
				cout << '+' << curCoeff;	
			if (xPow > 0)
				out << "*x^" << xPow;
			if (yPow > 0)
				out << "*y^" << yPow;
			if (zPow > 0)
				out << "*z^" << zPow;
			tL = tL->GetNextDatLink();
		}
	}
	out << endl;
	return out;
}
