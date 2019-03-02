#include <string>
#include "../include/polinom.h"
#include "../include/monom.h"

void sortm(int monoms[][2], int km)
{
  for(int i = 0; i < km - 1; ++i)
    for(int j = km - 1; j > i; --j)
    {
      if (monoms[j][1] == monoms[j - 1][1])
      {
        if (monoms[j][0] < monoms[j - 1][0])
        {
          int ctmp = monoms[j][0],
              itmp = monoms[j][1];
          monoms[j][0] = monoms[j - 1][0];
          monoms[j][1] = monoms[j - 1][1];
          monoms[j - 1][0] = ctmp;
          monoms[j - 1][1] = itmp;
        }
      }
      else if(monoms[j][1] < monoms[j - 1][1])
      {
        int ctmp = monoms[j][0],
            itmp = monoms[j][1];
        monoms[j][0] = monoms[j - 1][0];
        monoms[j][1] = monoms[j - 1][1];
        monoms[j - 1][0] = ctmp;
        monoms[j - 1][1] = itmp;
      }
    }
}

TPolinom::TPolinom(int monoms[][2], int km): THeadRing()
{
  PTMonom pMonom = new TMonom(0, -1);
  pHead->SetDatValue(pMonom);
  sortm(monoms, km);

  for(int i = 0; i < km; ++i)
  {
    if(monoms[i][1] < 0)
      throw -1;
    if(monoms[i][0] != 0)
    {
      pMonom = new TMonom(monoms[i][0], monoms[i][1]);
      InsLast(pMonom);
    }
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
    if(*pm < *qm)
    {
      rm = new TMonom(qm->Coeff, qm->Index);
      InsCurrent(rm);
      q.GoNext();
    }
    else if(*qm < *pm)
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
  q.DelList();

  TMonom m;

  while(true)
  {
    input >> m;
    if(m.GetIndex() == -1)
      break;
    else if(m.GetCoeff() != 0)
      q.InsLast(m.GetCopy());
  }

  return input;
}

