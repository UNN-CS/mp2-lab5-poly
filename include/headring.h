#include "datlist.h"

class THeadRing : public TDatList {
protected:
	PTDatLink pHead;     // заголовок, pFirst - будет следующим за pHead 
public:
	THeadRing();
	~THeadRing();
    
    //вставка
	virtual void InsFirst(PTDatValue pVal = NULL); // после заголовка
    
    //удаление											   
	virtual void DelFirst(void);                 
};
