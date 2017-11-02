#include "CList.h"

template <class Tr>
bool CList<T,Op>::find(T n, CNode<T>** &p)
{
	p = &m_head;
	while (*p && m_Op((*p)->m_data,n))
	{
		p = &((*p)->m_next);
	}
	return (*p)->m_data == n;
}

template <class Tr>
bool CList<T,Op>::insert(T n)
{
	CNode<T>** p;
	if (find (n,p)) return 0;
	
	CNode<T>* q = new CNode<T>(n);
	q->setNext(*p);
	*p = q;
	
	return 1;
}

template <class Tr>
bool CList<T,Op>::remove(T n)
{
	CNode<T>** p;
	if (!find (n,p)) return 0;
	CNode<T>* q = *p;
	(*p) = (*p)->getNext();
	delete q;
	return 1;
}

template <class Tr>
int CList<T,Op>::getSize()
{
	int isize = 0;
	CNode<T>* nTemp = getHead(); 
	while (nTemp != 0)
	{
		nTemp = nTemp.getNext();
		isize++;
	}
	return isize;
}

template <class Tr>
void CList<T,Op>::print()
{
	for (int i= 0; i < CList.getSize(); i++)
	{

	}
}
