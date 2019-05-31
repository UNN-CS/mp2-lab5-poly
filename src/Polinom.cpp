#include "Polinom.h"

TPolinom::TPolinom(int monoms[][2], int km)
{
    PTMonom h = new TMonom(0, -1);
    pHead->SetDatValue(h);

    PTMonom f = new TMonom(monoms[0][0], monoms[0][1]);
    InsFirst(f);

    for (int i = 1; i< km; i++)
    {
        PTMonom t = new TMonom(monoms[i][0], monoms[i][1]);

        for (; !IsListEnded(); GoNext())
        {
            if (t->GetIndex() >= (GetMonom()->GetIndex()))
                break;
        }
        InsCurrent(t);
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
    for (q.Reset(); !(q.IsListEnded()); q.GoNext())
    {
        for (Reset(); !(IsListEnded()); GoNext())
        {
            if (GetMonom()->Index == q.GetMonom()->Index)
            {
                if (GetMonom()->GetCoeff() == -(q.GetMonom()->GetCoeff()))
                {
                    DelCurrent();
                    break;
                }
                else
                {
                    GetMonom()->Coeff += q.GetMonom()->Coeff;
                    break;
                }
            }

            if (q.GetMonom()->Index > GetMonom()->Index)
            {
                InsCurrent(q.GetMonom());
                break;
            }
        }
        if (!(IsEmpty()) && pCurrLink == pStop)
            InsLast(q.GetMonom());
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