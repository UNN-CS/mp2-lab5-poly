#include "Polinom.h"

TPolinom::TPolinom(int monoms[][2], int km)
{
	PTMonom Mon = new TMonom(0, -1);
	pHead->SetDatValue(Mon);
	for (int i = 0; i < km; i++) 
	{		
		Mon = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(Mon);
	}	
};

TPolinom::TPolinom(TPolinom & q)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) 
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
};

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


TPolinom & TPolinom::operator=(TPolinom &q)
{
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy()); // delete pMonom;
	}
	return *this;
}; // ������������

std::ostream& operator<< (ostream &os, TPolinom &q)
{
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom pm = q.GetMonom();
		std::cout << "(" << pm->GetCoeff() << ", " << pm->GetIndex() << ") ";
	}
	return os;
};

bool TPolinom::operator==(TPolinom& q) {
	PTMonom pm, qm;
	Reset();
	q.Reset();
	while (true) {
		pm = GetMonom();
		qm = q.GetMonom();
		if (pm->Index != qm->Index)
			return 0;
		if (pm->Coeff != qm->Coeff)
			return 0;
		if (pm->Coeff != 0 && qm->Coeff == 0 || pm->Coeff == 0 && qm->Coeff != 0)
			return 0;
		else {
			if (pm->Coeff == 0 && qm->Coeff == 0)
				return 1;
			GoNext();
			q.GoNext();
		}
	}
}

bool TPolinom::operator !=(TPolinom& q) {
	return !(*this == q);
}