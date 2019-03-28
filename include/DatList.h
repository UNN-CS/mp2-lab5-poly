#ifndef __TDATLIST_H__
#define __TDATLIST_H__

#include<DatLink.h>

enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList  {
protected:
	PTDatLink pFirst;    // первое звено
	PTDatLink pLast;     // последнее звено
	PTDatLink pCurrLink; // текущее звено
	PTDatLink pPrevLink; // звено перед текущим
	PTDatLink pStop;     // значение указателя, означающего конец списка 
	int CurrPos;         // номер текущего звена (нумерация от 0)
	int ListLen;         // количество звеньев в списке
protected:  // методы
	PTDatLink GetLink(PTDatValue pVal = 0, PTDatLink pLink = 0);
	void      DelLink(PTDatLink pLink);   // удаление звена
public:
	TDatList();
	~TDatList() { DelList(); }
	// доступ
	PTDatValue GetDatValue(TLinkPos mode = CURRENT) const; // значение
	virtual int IsEmpty()  const { return pFirst == pStop; } // список пуст ?
	int GetListLength()    const { return ListLen; }       // к-во звеньев
	// навигация
	void SetCurrentPos(int pos);          // установить текущее звено
	int GetCurrentPos(void) const;       // получить номер тек. звена
	virtual void Reset(void);             // установить на начало списка
	virtual int IsListEnded(void) const; // список завершен ?
	void GoNext(void);                    // сдвиг вправо текущего звена
				// (=1 после применения GoNext для последнего звена списка)
	// вставка звеньев
	virtual void InsFirst(PTDatValue pVal = 0); // перед первым
	virtual void InsLast(PTDatValue pVal = 0); // вставить последним 
	virtual void InsCurrent(PTDatValue pVal = 0); // перед текущим 
	// удаление звеньев
	virtual void DelFirst(void);    // удалить первое звено 
	virtual void DelCurrent(void);    // удалить текущее звено 
	virtual void DelList(void);    // удалить весь список
};

#endif // __TDATLIST_H__