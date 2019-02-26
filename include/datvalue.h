#ifndef __DATVALUE_H__
#define __DATVALUE_H__

class TDatValue
{
public:
  virtual TDatValue* GetCopy() const=0;
  ~TDatValue(){}
};

#endif

