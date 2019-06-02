#pragma once
#include "TRootLink.h"
#include<iostream>


class TDatLink;
 typedef TDatLink* PTDatLink;

class TDatLink :public TRootLink
{
  protected:
	PTDatValue pValue; //”казатель на обьект значени€
  public:
	  TDatLink(PTDatValue pVal = nullptr, pTRootLink pN = nullptr) :  TRootLink(pN) {
		  pValue = pVal;
	  }
	  void       SetDatValue(PTDatValue pVal) { pValue = pVal; }
	  PTDatValue GetDatValue() { return pValue; }
	  PTDatLink  GetNextDatLink() { return (PTDatLink)pNext; }
	  friend class TDatList;
};


 