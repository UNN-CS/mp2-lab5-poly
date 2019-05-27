#include <datlist.h>

TDatList::TDatList() //DONE
{
	pStop = NULL;
	pFirst = NULL;   
	pLast = NULL;
	ListLen = 0;
	Reset();
}

PTDatValue TDatList::GetDatValue(TLinkPos mode = CURRENT) const 
{
    PTDatLink tmp;
    switch (mode) {
    case FIRST: tmp = pFirst; break;
    case LAST: tmp = pLast; break;
    default: tmp = pCurrLink; break;
    }

    return (tmp == NULL) ? NULL : tmp->pValue;
}

int TDatList::SetCurrentPos(int pos) //DONE
{
	if (pos >= ListLen || pos < 0) throw -1;

	Reset();
	for (int i = 0; i < pos; ++i)
	{
		this->GoNext();
	}

	return 0;
}

int TDatList::GetCurrentPos(void) const //DONE
{
	return CurrPos;
}

int TDatList::Reset(void) //DONE
{
	pPrevLink = pStop;
	pCurrLink = pFirst;

	if (IsEmpty()) 
	{
		pCurrLink = pStop;
		CurrPos = -1;
	}
	else 
	{
		pCurrLink = pFirst;
		CurrPos = 0;
	}
}

int TDatList::IsListEnded(void) const //DONE
{
	return pCurrLink == pStop;
}

int TDatList::GoNext(void) //DONE
{
	if (IsListEnded()) throw -1;

	pPrevLink = pCurrLink;
	pCurrLink = pCurrLink->GetNextDatLink();
	CurrPos++;

	return 0;

} 

void TDatList::InsFirst(PTDatValue pVal = NULL) //DONE
{
	PTDatLink tmp = GetLink(pVal, pFirst);
	if (!tmp) throw -1;

	if (this->IsEmpty())
	{
		pLast = pFirst = tmp;
		Reset();

	}
	else if (this->ListLen == 1)
	{
		pLast = pFirst;
		pFirst = tmp;
	}
	else
	{
		pFirst = tmp;
	}

	if (CurrPos == 0)
	{
		pCurrLink = tmp;
	}
	else
	{
		++CurrPos;
	}

	++ListLen;

}

void TDatList::InsLast(PTDatValue pVal = NULL) //DONE
{
	PTDatLink tmp = GetLink(pVal, pStop);

	if (this->IsEmpty())
	{
		pLast = pFirst = tmp;
		Reset();

	}
	else
	{
		pLast->pNext = tmp;
		pLast = tmp;
	}

	++ListLen;

	if (IsListEnded())
	{
		this->pCurrLink = tmp;
	}

}

void TDatList::InsCurrent(PTDatValue pVal = NULL) //DONE
{
	if (this->IsEmpty() || this->pCurrLink == pFirst)
	{
		InsFirst(pVal);
	}
	else if (IsListEnded())
	{
		InsLast();
	}
	else
	{
		PTDatLink tmp = GetLink(pVal, pCurrLink);

		if (!tmp) throw -1;

		pPrevLink->SetNextLink(tmp);
		pCurrLink = tmp;
		ListLen++;
	}
}


												
void TDatList::DelFirst(void) //DONE
{
	if (IsEmpty()) throw -1;

	PTDatLink tmp = pFirst->pNext;
	DelLink (pFirst);
	pFirst = tmp;
	ListLen--;

	if (IsEmpty())
	{
		pLast = pStop;
		Reset();
	}
	else
	{
		if (CurrPos == 0)
		{
			pCurrLink = pFirst;

		}
		if (CurrPos == 1)
		{
			pPrevLink = pStop;
		}
		else if (CurrPos > 0)
		{
			CurrPos--;
		}
	}
		
}




void TDatList::DelCurrent(void) //DONE
{
	if (this->IsEmpty() || pCurrLink == pStop) throw -1;

	if (ListLen == 1 || pCurrLink == pFirst)
	{
		this->DelFirst();
	}
	else
	{
		PTDatLink tmp = pCurrLink;

		if (pCurrLink == pLast) 
		{
			pLast = pPrevLink;
			pCurrLink = pStop;
		}
		pCurrLink = pCurrLink->GetNextDatLink();
		pPrevLink->SetNextLink(pCurrLink);
		DelLink(tmp);
		--ListLen;
	}


}

void TDatList::DelList(void) //DONE
{
	while (!IsEmpty())
	{
		DelFirst();
	}
	Reset();
}

PTDatLink TDatList::GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL) //DONE
{
	PTDatLink tmp = new TDatLink(pVal, pLink);
	if (!tmp) throw -1;
	return tmp;
}

void TDatList::DelLink(PTDatLink pLink) //DONE
{
	if (pLink != NULL)
	{
		if (pLink->pValue != NULL)
			delete pLink->pValue;
		delete pLink;
	}
}