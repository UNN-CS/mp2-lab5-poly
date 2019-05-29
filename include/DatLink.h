#pragma once
 #include "DatValue.h"
 #include "RootLink.h"

 
  class TDatLink;
 typedef TDatLink *PTDatLink;

  class TDatLink : public TRootLink
 {
 protected:
 	PTDatValue pValue; // óêàçàòåëü íà îáúåêò çíà÷åíèÿ
 public:
 	TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) : TRootLink(pN)
 	{
 		pValue = pVal;
 	}
 	void SetDatValue(PTDatValue pVal) { pValue = pVal; }
 	PTDatValue GetDatValue() { return pValue; }
 	PTDatLink GetNextDatLink() { return (PTDatLink)pNext; }

  	friend class TDatList;
 };