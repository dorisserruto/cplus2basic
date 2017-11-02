#include "CList.h";

template <class T, class Op>
bool CList<T>::find(T n, CNode<T>** &p)
{
	p = &m_head;
	while (*p && m_Op((*p)->m_data,n))
	{
		p = &((*p)->m_next);
	}
	return (*p)->m_data == n;
}

template <class T, class Op>
bool CList<T>::insert(T n)
{
	CNode<T>** p;
	if (find (n,p)) return 0;
	
	CNode<T>* q = new CNode<T>(n);
	q->setNext(*p);
	*p = q;
	
	return 1;
}

template <class T, class Op>
bool CList<T>::remove(T n)
{
	CNode<T>** p;
	if (!find (n,p)) return 0;
	CNode<T>* q = *p;
	(*p) = (*p)->getNext();
	delete q;
	return 1;
}

template <class T, class Op>
int getSize()
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

template <class T, class Op>
void print()
{
	for (int i= 0; i < CList.getSize(); i++)
	{

	}
}

