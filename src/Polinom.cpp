#include "Polinom.h"

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
    DelList();

    for (q.Reset(); !(q.IsListEnded()); q.GoNext())
        InsLast(q.GetMonom());
}

PTMonom TPolinom::GetMonom()
{
    return (PTMonom)GetDatValue();
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
    if (this != &q)
    {
        DelList();
        for (q.Reset(); !(q.IsListEnded()); q.GoNext())
            InsLast(q.GetMonom());
    }

    return *this;
}

bool TPolinom::operator==(TPolinom& q) {
    PTMonom pm, qm;
    Reset();
    q.Reset();
    while (true) {
        pm = GetMonom();
        qm = q.GetMonom();
        if (pm->Index != qm->Index)
            return false;
        if (pm->Coeff != qm->Coeff)
            return false;
        if (pm->Coeff != 0 && qm->Coeff == 0 || pm->Coeff == 0 && qm->Coeff != 0)
            return false;
        else {
            if (pm->Coeff == 0 && qm->Coeff == 0)
                return true;
            GoNext();
            q.GoNext();
        }
    }
}

bool TPolinom::operator !=(TPolinom& q) {
    return !(*this == q);
}

void TPolinom::Print()
{
    int cx, cy, cz, cf;
    for (Reset(); !(IsListEnded()); GoNext())
    {
        cf = GetMonom()->GetCoeff();

        if (pCurrLink != pFirst)
            if (cf > 0)
                std::cout << "+";
        std::cout << cf;

        cx = (GetMonom()->GetIndex()) / 100;
        if (cx != 0)
            std::cout << "x";
        if (cx != 1)
            std::cout << "^" << cx;

        cy = (GetMonom()->GetIndex() % 100) / 10;
        if (cy != 0)
            std::cout << "y";
        if (cy != 1)
            std::cout << "^" << cy;

        cz = (GetMonom()->GetIndex() % 100) % 10;
        if (cz != 0)
            std::cout << "z";
        if (cz != 1)
            std::cout << "^" << cz;
    }
    std::cout << std::endl;
}