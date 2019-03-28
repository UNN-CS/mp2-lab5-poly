#include "Polinom.h"

using namespace std;

TPolinom::TPolinom(int monoms[][2], int km)
{
	if (km < 0) throw - 1;
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	
	for (int i = 0; i < km; ++i)
	{
		pMonom = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(pMonom);
	}
}

TPolinom::TPolinom(TPolinom &q)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
}

TPolinom& TPolinom::operator=(TPolinom& q) {
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
	return *this;
}


TPolinom & TPolinom::operator+=(TPolinom &q)
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

void TPolinom::Print()
{
	for (Reset(); !IsListEnded(); GoNext())
	{
		this->GetMonom()->Print();
	}
}