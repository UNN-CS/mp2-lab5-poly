#include "tdatlist.h"

class THeadRing : public TDatList {
protected:
	PTDatLink pHead;     
public:
	THeadRing();
	~THeadRing();
	// âñòàâêà çâåíüåâ
	virtual void InsFirst(PTDatValue pVal = NULL); 
	// óäàëåíèå çâåíüåâ
	virtual void DelFirst(void);                 
};