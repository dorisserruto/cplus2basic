#include "Node.h"

template <class Tr>
class TreeIterator
{
public:
	typedef typename Tr::T T;
	typedef typename Tr::OpI iterator_op_mode;
	typedef typename TreeIterator<T> self;
	
	Node<T>* i;

	TreeIterator(Node<T>* i){
		this.i = i;
	}
	
	self operator = (self &r){
		this.i = r.i;
		return *this;
	}

	bool operator != (self &r){
		return (this.i != r.i);
	}

	T operator *(){
		return this.i->data;
	}

	self operator ++(){
		iterator_op_mode()(i);
	}

	friend class OpInOrder;
};