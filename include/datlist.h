#include "datlink.h"

enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList {
protected:
	PTDatLink pFirst;    
	PTDatLink pLast;     
	PTDatLink pCurrLink;  // текущее звено
	PTDatLink pPrevLink; // звено перед текущим
	PTDatLink pStop;   // значение указателя, означающего конец списка    
	int CurrPos;         // номер текущего звена (нумерация от 0)
	int ListLen;         // количество звеньев в списке
    protected:  
    PTDatLink GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL);
	void      DelLink(PTDatLink pLink);   
    public:
	TDatList();
	~TDatList() { DelList(); }
	
    // доступ
	PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; // значение
	virtual int IsEmpty()  const { return pFirst == pStop; } // проверка пустоты
	int GetListLength()    const { return ListLen; }   // количество звеньев    
	
    // навигация
	int SetCurrentPos(int pos);     // установить текущее звено      
    int GetCurrentPos(void) const;       // получить номер тек. звена
	virtual int Reset(void);              // установить текущим первое звено
	virtual int IsListEnded(void) const;  // список завершен
	int GoNext(void);                    // сдвиг вправо текущего звена
										 
	// вставка звеньев									 
	virtual void InsFirst(PTDatValue pVal = NULL); // перед первым
	virtual void InsLast(PTDatValue pVal = NULL); // вставить последним 
	virtual void InsCurrent(PTDatValue pVal = NULL); // перед текущим 
		
    // удаление звеньев
	virtual void DelFirst(void);    
	virtual void DelCurrent(void);   
	virtual void DelList(void);     
};

typedef TDatList *PTDatList;