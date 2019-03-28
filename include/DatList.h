#ifndef __TDATLIST_H__
#define __TDATLIST_H__

#include<DatLink.h>

enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList  {
protected:
	PTDatLink pFirst;    // ������ �����
	PTDatLink pLast;     // ��������� �����
	PTDatLink pCurrLink; // ������� �����
	PTDatLink pPrevLink; // ����� ����� �������
	PTDatLink pStop;     // �������� ���������, ����������� ����� ������ 
	int CurrPos;         // ����� �������� ����� (��������� �� 0)
	int ListLen;         // ���������� ������� � ������
protected:  // ������
	PTDatLink GetLink(PTDatValue pVal = 0, PTDatLink pLink = 0);
	void      DelLink(PTDatLink pLink);   // �������� �����
public:
	TDatList();
	~TDatList() { DelList(); }
	// ������
	PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; // ��������
	virtual int IsEmpty()  const { return pFirst == pStop; } // ������ ���� ?
	int GetListLength()    const { return ListLen; }       // �-�� �������
	// ���������
	void SetCurrentPos(int pos);          // ���������� ������� �����
	int GetCurrentPos(void) const;       // �������� ����� ���. �����
	virtual void Reset(void);             // ���������� �� ������ ������
	virtual int IsListEnded(void) const; // ������ �������� ?
	void GoNext(void);                    // ����� ������ �������� �����
				// (=1 ����� ���������� GoNext ��� ���������� ����� ������)
	// ������� �������
	virtual void InsFirst(PTDatValue pVal = 0); // ����� ������
	virtual void InsLast(PTDatValue pVal = 0); // �������� ��������� 
	virtual void InsCurrent(PTDatValue pVal = 0); // ����� ������� 
	// �������� �������
	virtual void DelFirst(void);    // ������� ������ ����� 
	virtual void DelCurrent(void);    // ������� ������� ����� 
	virtual void DelList(void);    // ������� ���� ������
};

#endif // __TDATLIST_H__