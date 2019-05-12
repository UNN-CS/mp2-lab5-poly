#ifndef __DATLIST_H
#define __DATLIST_H

#include "DatLink.h"
// #include "DataCom.h"

#define ListOK 0 // ������ ���
#define ListEmpty -101 // ������ ����
#define ListNoMem -102 // ��� ������
#define ListNoPos -103 // ��������� ��������� ���������

enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList {
protected:
    PTDatLink pFirst; // ������ �����
    PTDatLink pLast; // ��������� �����
    PTDatLink pCurrLink; // ������� �����
    PTDatLink pPrevLink; // ����� ����� �������
    PTDatLink pStop; // �������� ���������, ����������� ����� ������
    int CurrPos; // ����� �������� ����� (��������� �� 0)
    int ListLen; // ���������� ������� � ������
protected: // ������
    PTDatLink GetLink(PTDatValue pVal = nullptr, PTDatLink pLink = nullptr);
    void DelLink(PTDatLink pLink); // �������� �����
public:
    TDatList();
    ~TDatList() { DelList(); }
    // ������
    PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; // ��������
    virtual int IsEmpty() const { return pFirst == pStop; } // ������ ����?
    int GetListLength() const { return ListLen; } // �-�� �������
    // ���������
    int SetCurrentPos(int pos); // ���������� ������� �����
    int GetCurrentPos(void) const; // �������� ����� ���. �����
    virtual int Reset(void); // ���������� �� ������ ������
    virtual int IsListEnded(void) const; // ������ ��������?
    int GoNext(void); // ����� ������ �������� �����
    // (=1 ����� ���������� GoNext ��� ���������� ����� ������)
    // ������� �������
    virtual void InsFirst(PTDatValue pVal = nullptr); // ����� ������
    virtual void InsLast(PTDatValue pVal = nullptr); // �������� ���������
    virtual void InsCurrent(PTDatValue pVal = nullptr); // ����� �������
    // �������� �������
    virtual void DelFirst(void); // ������� ������ �����
    virtual void DelCurrent(void); // ������� ������� �����
    virtual void DelList(void); // ������� ���� ������
};

typedef TDatList* PTDatList;
#endif
