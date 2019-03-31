#ifndef __THEADRING_H__
#define __THEADRING_H__

#include "DatList.h"

class THeadRing : public TDatList {
protected:
	PTDatLink pHead;     // çàãîëîâîê, pFirst - çâåíî çà pHead
public:
	THeadRing();
	~THeadRing();
	// âñòàâêà çâåíüåâ
	virtual void InsFirst(PTDatValue pVal = NULL); // ïîñëå çàãîëîâêà
												   // óäàëåíèå çâåíüåâ
	virtual void DelFirst();                 // óäàëèòü ïåðâîå çâåíî
};

#endif // __THEADRING_H__