#ifndef __TDATLIST_H__
#define __TDATLIST_H__

#include "DatLink.h"
#include "DatValue.h"


#define ListEmpty -101 // список пуст
#define ListNoMem -102 // нет памяти
#define ListNoPos -103 // ошибочное положение текущего указателя

enum TLinkPos {FIRST, CURRENT, LAST};

class TDatList {
  protected:
    PTDatLink pFirst;    // первое звено
    PTDatLink pLast;     // последнее звено
    PTDatLink pCurrLink; // текущее звено
    PTDatLink pPrevLink; // звено перед текущим
    PTDatLink pStop;     // значение указателя, означающего конец списка
    int CurrPos;         // номер текущего звена (нумерация от 0)
    int ListLen;         // количество звеньев в списке
  protected:  // методы
    PTDatLink GetLink ( PTDatValue pVal=NULL, PTDatLink pLink=NULL );
    void      DelLink ( PTDatLink pLink );   // удаление звена
  public:
    TDatList();
    ~TDatList() { DelList(); }
    // доступ
    PTDatValue GetDatValue ( TLinkPos mode = CURRENT ) const; // значение
    virtual int IsEmpty()  const { return pFirst==pStop; } // список пуст ?
    int GetListLength()    const { return ListLen; }       // к-во звеньев
    // навигация
    void SetCurrentPos ( int pos );          // установить текущее звено
    int GetCurrentPos () const;       // получить номер тек. звена
    virtual void Reset ();             // установить на начало списка
    virtual int IsListEnded () const; // список завершен ?
    void GoNext ();                    // сдвиг вправо текущего звена
                // (=1 после применения GoNext для последнего звена списка)
    // вставка звеньев
    virtual void InsFirst  ( PTDatValue pVal=NULL ); // перед первым
    virtual void InsLast   ( PTDatValue pVal=NULL ); // вставить последним
    virtual void InsCurrent( PTDatValue pVal=NULL ); // перед текущим
    // удаление звеньев
    virtual void DelFirst  ();    // удалить первое звено
    virtual void DelCurrent();    // удалить текущее звено
    virtual void DelList   ();    // удалить весь список
};

#endif // __TDATLIST_H__
