#pragma once
 #include "DatList.h"
 #include "DatLink.h"
 #include "DatValue.h"
 class THeadRing : public TDatList
 {
 protected:
 	PTDatLink pHead; 
 public:
 	THeadRing();
 	~THeadRing();
 	
 	virtual void InsFirst(PTDatValue pVal = NULL); 
 	
 	virtual void DelFirst(void); 
 };