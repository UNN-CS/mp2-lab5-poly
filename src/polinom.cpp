#include <string>
#include "../include/polinom.h"

TPolinom::TPolinom(int monoms[][2], int km): THeadRing()
{
  PTMonom pMonom = new TMonom(0, -1);
  pHead->SetDatValue(pMonom);
  for(int i = 0; i < km; ++i)
  {
    if(monoms[i][1] < 0)
      throw -1;
    pMonom = new TMonom(monoms[i][0], monoms[i][1]);
    InsLast(pMonom);
  }
}

TPolinom::TPolinom(TPolinom &q): THeadRing()
{
  PTMonom pMonom = new TMonom(0, -1);

  pHead->SetDatValue(pMonom);

  for(q.Reset(); !q.IsListEnded(); q.GoNext())
    InsLast(q.GetMonom()->GetCopy());
}

TPolinom& TPolinom::operator=(TPolinom& q)
{
  if(this == &q)
    return *this;

  TPolinom& q = const_cast<TPolinom&>(q);
  int pos = q.GetCurrentPos();

  DelList();

  for(q.Reset(); !q.IsListEnded(); q.GoNext())
    InsLast(q.GetMonom()->GetCopy());

  q.SetCurrentPos(pos);

  return *this;
}

TPolinom& TPolinom::operator+=(TPolinom& q)
{
  PTMonom pm, qm, rm;

  Reset();
  q.Reset();

  while(true)
  {
    pm = GetMonom();
    qm = q.GetMonom();
    if(pm->Index < qm->Index)
    {
      rm = new TMonom(qm->Coeff, qm->Index);
      InsCurrent(rm);
      q.GoNext();
    }
    else if(pm->Index > qm->Index)
    {
      GoNext();
    }
    else
    {
      if(pm->Index == -1)
        break;
      pm->Coeff += qm->GetCoeff();
      if(pm->Coeff != 0)
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

std::ostream& operator<<(std::ostream &output, TPolinom &q)
{
  PTMonom pMonom = nullptr;
  for(q.Reset(); !q.IsListEnded(); q.GoNext())
  {
    pMonom = q.GetMonom();
    if(pMonom != nullptr)
      output << *pMonom << ' ';
  }
  return output;
}

std::istream& operator>>(std::istream &input, TPolinom &q)
{
  q.GetMonom();
  return input;
}

