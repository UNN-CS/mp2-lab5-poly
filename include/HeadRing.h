#include "DatList.h"

class THeadRing : public TDatList {
protected:
	PTDatLink pHead;     // ���������, pFirst - ����� �� pHead
public:
	THeadRing();
	~THeadRing();
	// ������� �������
	virtual void InsFirst(PTDatValue pVal = 0); // ����� ���������
	// �������� �������
	virtual void DelFirst(void);                 // ������� ������ �����
};
