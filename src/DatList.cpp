#include "DatList.h"

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
	return PTDatLink();
}

void TDatList::DelLink(PTDatLink pLink)
{
}

TDatList::TDatList()
{
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{
	return PTDatValue();
}

int TDatList::SetCurrentPos(int pos)
{
	return 0;
}

int TDatList::GetCurrentPos(void) const
{
	return 0;
}

int TDatList::Reset(void)
{
	return 0;
}

int TDatList::IsListEnded(void) const
{
	return 0;
}

int TDatList::GoNext(void)
{
	return 0;
}

void TDatList::InsFirst(PTDatValue pVal)
{
}

void TDatList::InsLast(PTDatValue pVal)
{
}

void TDatList::InsCurrent(PTDatValue pVal)
{
}

void TDatList::DelFirst(void)
{
}

void TDatList::DelCurrent(void)
{
}

void TDatList::DelList(void)
{
}
