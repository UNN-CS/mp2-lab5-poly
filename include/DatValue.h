//DatValue.h Ц модуль, объ€вл€ющий абстрактный класс объектов-значений списка

#ifndef __DATVALUE_H__
#define __DATVALUE_H__

typedef TDatValue *PTDatValue;

class TDatValue 
{
public:
	virtual TDatValue * GetCopy() = 0; // создание копии
	~TDatValue() {}
};

#endif // __DATVALUE_H__
