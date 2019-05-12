#include "Polinom.h"

TPolinom::TPolinom(int monoms[][2], int km) {
    PTMonom pMonom = new TMonom(0, -1);
    pHead->SetDatValue(pMonom);
    for (int i = 0; i < km; ++i) {
        if (monoms[i][1] < 0 || monoms[i][1] > 999)
            throw "Wrong index";
        pMonom = new TMonom(monoms[i][0], monoms[i][1]);
        InsLast(pMonom);
    }
}

TPolinom& TPolinom::operator+=(TPolinom& q) {
    PTMonom pm, qm, rm;
    Reset();
    q.Reset();
    while (1) {
        pm = GetMonom();
        qm = q.GetMonom();
        if (pm->Index < qm->Index) {
            rm = new TMonom(qm->Coeff, qm->Index);
            InsCurrent(rm);
            q.GoNext();
        }
        else if (pm->Index > qm->Index)
            GoNext();
        else { // индексы мономов равны (но это могут быть головы!)
            if (pm->Index == -1)
                break;
            pm->Coeff += qm->Coeff;
            if (pm->Coeff != 0) {
                GoNext();
                q.GoNext();
            }
            else { // удаление монома с нулевым коэффициентом
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
        InsLast(pMonom->GetCopy);
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

bool TPolinom::operator==(TPolinom& q) {
    if (GetListLength() != q.GetListLength())
        return 0;
    else {
        PTMonom pm, qm;
        Reset();
        q.Reset();
        while (1) {
            if (pm->Coeff != qm->Coeff ||
                pm->Index != qm->Index)
                return 0;
            // проверка голов
            if (pm->Index == -1 && qm->Index == -1)
                return 1;
            GoNext();
            q.GoNext();
        }
    }
}

bool TPolinom::operator!=(TPolinom& q) {
    return !(*this == q);
}

std::ostream& operator<<(std::ostream& os, TPolinom& q) {
    for (q.Reset(); !q.IsListEnded(); q.GoNext())
        os << (*q.GetMonom()).GetIndex << ' ' << (*q.GetMonom()).GetCoeff() << std::endl;
    return os;
}
