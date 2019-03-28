#include <string>
#include "../include/polinom.h"
#include "../include/monom.h"

void sortm(int monoms[][2], int km)
{
  int ctmp, itmp;
  for(int i = 0; i < km - 1; ++i)
    for(int j = km - 1; j > i; --j)
    {
      if(monoms[j][1] > monoms[j - 1][1])
      {
        ctmp = monoms[j][0];
        itmp = monoms[j][1];
        monoms[j][0] = monoms[j - 1][0];
        monoms[j][1] = monoms[j - 1][1];
        monoms[j - 1][0] = ctmp;
        monoms[j - 1][1] = itmp;
      }
    }


  //add monoms with same index
  for(int i = 0; i < km - 1; ++i)
  {
    if(monoms[i][1] == monoms[i + 1][1])
    {
      int j;
      for(j = i + 1; monoms[i][1] == monoms[j][1]; ++j)
      {
        monoms[i][0] += monoms[j][0];
        monoms[j][0] = 0;
      }
      i = j - 1;
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

    if(pm->Index < qm->Index)
    {
      rm = new TMonom(qm->Coeff, qm->Index);
      InsCurrent(rm);
      q.GoNext();
    }
    else if(qm->Index < pm->Index)
    {
      GoNext();
    }
    else
    {
      if(pm->Index == -1)
        break;
      pm->Coeff += qm->Coeff;
      if(pm->Coeff != 0)
        GoNext();
      else
        DelCurrent();
      q.GoNext();
    }
  }

  return *this;
}

std::ostream& operator<<(std::ostream &output, TPolinom &q)
{
  if(q.IsEmpty())
  {
    output << 0;
    return output;
  }
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
  int cval, ival;

  int (*buf)[2] = new int[8][2],
      km = 0,
      sz = 8;

  while(true)
  {
    input >> cval;
    input >> ival;

    if(ival == -1)
      break;
    else
    {
      buf[km][0] = cval;
      buf[km][1] = ival;
      ++km;
      if(km == sz)
      {
        int (*tmp)[2] = new int[sz * 2][2];
        for(int i = 0; i < sz; ++i)
        {
          tmp[i][0] = buf[i][0];
          tmp[i][1] = buf[i][1];
        }
        sz *= 2;
        delete[] buf;
        buf = tmp;
      }
    }
  }

  TPolinom poly(buf, km);
  q = poly;

  delete[] buf;
  return input;
}

