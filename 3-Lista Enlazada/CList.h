#include "CNode.h"

using namespace std;

template <class T, class Op>
//template <class T, class Op = CLess <T>> -> para usar por defecto CLess
class CList
{
private:
	CNode<T>* m_head;
	Op m_Op;

public:
	CList();
	~CList();

	bool find (T n, CNode<T>** &p);
	bool insert (T n);
	bool remove (T n);
	void print();
	
	int getSize();
	CNode<T>* getHead();
};
