#include <iostream>
#include "DatLink.h"

#define ListOK 0
#define ListEmpty -101
#define ListNoMem -102
#define ListNoPos -103

enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList 
{
protected:
	PTDatLink pFirst;    // ������ �����
	PTDatLink pLast;     // ��������� �����
	PTDatLink pCurrLink; // ������� �����
	PTDatLink pPrevLink; // ����� ����� �������
	PTDatLink pStop;     // �������� ���������, ����������� ����� ������ 
	int CurrPos;         // ����� �������� ����� (��������� �� 0)
	int ListLen;         // ���������� ������� � ������
	int RetCode;
protected:  // ������
	PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL);
	void      DelLink(PTDatLink pLink);   // �������� �����
public:
	TDatList();
	~TDatList() { DelList(); };
	// ������
	PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; // ��������
	virtual int IsEmpty()  const { return pFirst == pStop; } // ������ ���� ?
	int GetListLength()    const { return ListLen; }       // �-�� �������
	// ���������
	void SetCurrentPos(int pos);          // ���������� ������� �����
	int GetCurrentPos(void) const;       // �������� ����� ���. �����
	virtual void Reset(void);             // ���������� �� ������ ������
	virtual int IsListEnded(void) const; // ������ �������� ?
	int GoNext(void);                    // ����� ������ �������� �����
				// (=1 ����� ���������� GoNext ��� ���������� ����� ������)
	// ������� �������
	virtual void InsFirst(PTDatValue pVal = NULL); // ����� ������
	virtual void InsLast(PTDatValue pVal = NULL); // �������� ��������� 
	virtual void InsCurrent(PTDatValue pVal = NULL); // ����� ������� 
	// �������� �������
	virtual void DelFirst(void);    // ������� ������ ����� 
	virtual void DelCurrent(void);    // ������� ������� ����� 
	virtual void DelList(void);    // ������� ���� ������
	void SetRetCode(int code) { RetCode = code; };
	int GetRetCode() { return RetCode; };
};
