#ifndef __DATVALUE_H
#define __DATVALUE_H

class TDatValue {
public:
	virtual TDatValue * GetCopy() = 0; // ñîçäàíèå êîïèè
	~TDatValue() {}
};
typedef TDatValue *PTDatValue;
#endif