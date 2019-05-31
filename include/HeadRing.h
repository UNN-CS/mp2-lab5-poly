//Циклически списки с загловками

#ifndef __HEADRING_H
#define __HEADRING_H

#include "DatList.h"

class THeadRing : public TDatList {
protected:
	PTDatLink pHead;     // заголовок, pFirst - звено на pHead
public:
	THeadRing();
	~THeadRing();
	// вставка звеньев
	virtual void InsFirst(PTDatValue pVal = NULL); // вставить после заголовка
    // удаление звеньев
	virtual void DelFirst(void);                // удалить первое звено
};

#endif // !__HEADRING_H