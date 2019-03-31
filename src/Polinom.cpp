#include <Polinom.h>

TPolinom::TPolinom(int monoms[][2], int km) : THeadRing()
{
	 PTMonom tmp = new TMonom(0,-1);
	 pHead->SetDatValue(tmp);

	 for (int i = 0; i < km; i++)
	 {
		 PTMonom tmp = new TMonom(monoms[i][0], monoms[i][1]);
		 InsLast(tmp);
	 }
}

TPolinom::TPolinom(TPolinom &q)
{
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);

	q.Reset();
    while (q.IsListEnded())
	{
		PTMonom tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
		q.GoNext();
	}
}

TPolinom TPolinom::operator+(TPolinom &q) // сложение полиномов
{
	TPolinom tmp = TPolinom();
	PTMonom lm, rm, tmpM;
	Reset();
	q.Reset();

	while (true)
	{
		lm = GetMonom();
		rm = q.GetMonom();

		if (this->IsListEnded() || q.IsListEnded())
		{
			if (this->IsListEnded() && q.IsListEnded())
				break;
			else if (this->IsListEnded())
			{
				while (!q.IsListEnded())
				{
					rm = q.GetMonom();

					tmpM = new TMonom(rm->Coeff, rm->Index);
					tmp.InsLast(tmpM);

					q.GoNext();
				}
			}
			else // q is ended
			{
				while (!this->IsListEnded())
				{
					lm = this->GetMonom();

					tmpM = new TMonom(lm->Coeff, lm->Index);
					tmp.InsLast(tmpM);

				    this->GoNext();
				}
			}
			break;
		}
		else if (lm->Index < rm->Index)
		{
			tmpM = new TMonom(lm->Coeff, lm->Index);
			tmp.InsLast(tmpM);

			this->GoNext();
		}
		else if(lm->Index > rm->Index)
		{
			tmpM = new TMonom(rm->Coeff, rm->Index);

		}
		else // lm->Index == rm->Index
		{
			tmpM = new TMonom(rm->Coeff+lm->Coeff, rm->Index);
			tmp.InsLast(tmpM);

			this->GoNext();
			q.GoNext();
		}
	}

	return tmp;
}

bool  TPolinom::operator==(TPolinom &q)
{
    PTMonom pm, qm;
    Reset();
    q.Reset();
    while(true) {
        pm = GetMonom();
        qm = q.GetMonom();
        if(pm -> Index != qm -> Index)
            return 0;
        if(pm->Coeff != qm -> Coeff)
            return 0;
        if((pm -> Coeff != 0 && qm -> Coeff == 0) || (pm -> Coeff == 0 && qm -> Coeff != 0)
            return 0;
        else {
            if(pm -> Coeff == 0 && qm -> Coeff == 0)
                return 1;
            GoNext();
            q.GoNext();
        }
    }
}

TPolinom & TPolinom::operator=(TPolinom &q) // присваивание
{
	DelList();

	q.Reset();
	while (q.IsListEnded())
	{
		PTMonom tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
		q.GoNext();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, TPolinom& q)
{
	q.Reset();
	while (!q.IsListEnded())
	{
		os << "Coeff: " << q.GetMonom()->GetCoeff() << " Index: " << q.GetMonom()->GetIndex() << std::endl;

		q.GoNext();
	}

	return os;
}
