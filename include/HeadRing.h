#pragma once
#include "DatList.h"


class THeadRing : public TDatList {
protected:
	PTDatLink pHead;     // ���������, pFirst - ����� �� pHead
public:
	THeadRing();
	~THeadRing();
	// ������� �������
	virtual void InsFirst(PTDatValue pVal = NULL); // ����� ���������
	// �������� �������
	virtual void DelFirst(void);                 // ������� ������ �����
};


