#include <iostream.h>

class TDatValue {
  public:
    virtual TDatValue * GetCopy() =0; // �������� �����
   ~TDatValue() {}
};

typedef TDatValue *PTDatValue;
