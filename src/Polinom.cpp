#include <polinom.h>

TPolinom::TPolinom(int monoms[][2], int km) 
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	for (int i = 0; i < km; ++i) 
	{
		pMonom = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(pMonom);
	}
}

TPolinom::TPolinom(TPolinom& q) 
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
}

TPolinom& TPolinom::operator+ (TPolinom& q)
{

}

TPolinom &TPolinom::operator+=(TPolinom& q) 
{
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (true) 
	{
		pm = GetMonom();
		qm = q.GetMonom();
		if (pm->Index < qm->Index) {
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm);
			q.GoNext();
		}
		else if (pm->Index > qm->Index)
			GoNext();
		else {
			if (pm->Index == -1)
				break;
			pm->Coeff += qm->Coeff;
			if (pm->Coeff != 0) {
				GoNext();
				q.GoNext();
			}
			else {
				DelCurrent();
				q.GoNext();
			}
		}
	}
	return *this;
}

TPolinom::TPolinom(TPolinom& q) {
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
}

TPolinom &TPolinom::operator=(TPolinom& q) {
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		PTMonom pMonom = q.GetMonom();
		InsLast(pMonom->GetCopy());
	}
	return *this;
}

bool TPolinom::operator==(TPolinom &q) 
{
	this->Reset();
	q.Reset();
	while (true) 
	{
		if (this->IsListEnded() || q.IsListEnded()) {
			if (this->IsListEnded() && q.IsListEnded())
				return true;
			return false;
		}
		if (*this->GetMonom() != *q.GetMonom())
			return false;
		this->GoNext();
		q.GoNext();
	}
}

std::ostream& operator<<(std::ostream& out, TPolinom& q) 
{
	
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		out << *q.GetMonom() << std::endl;
	}
	
	return out;
}

std::istream& operator>>(std::istream& in, TPolinom& q) {
	
	return in;
}