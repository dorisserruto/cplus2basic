#include "Node.h"
#include "DoubleListIterator.h"

template < class Tr >
class DoubleList
{
public:
	typedef typename Tr::T T;
	typedef typename Tr::Op Op;
	typedef typename DoubleListIterator<Tr> iterator;

private:
	Node<T>* head;
	Node<T>* tail;

public:
	DoubleList(){
		head = 0;
		tail = new Node<T>(0);
	}

	bool find(T n, Node<T>**& p);
	bool insert(T n);
	bool remove(T n);

	int get_size();
	void print();

	iterator begin();
	iterator end();

};

template < class Tr >
/*find: Modificado para devolver el nodo previo a la posicion*/
bool DoubleList<Tr>::find(T n, Node<T>**& p){
	bool finded = false;
	Node<T>** prev = p = &head;

	while ( *p && Op()((*p)->get_data(),n) ){
		prev = p;
		Node<T>* new_next = (*p)->get_next();
		p = &(new_next);
	}
	if ( (*p) != 0 && (*p)->get_data() == n ){
		finded = true;
	}
	p = prev;
	return finded;
}

template < class Tr >
bool DoubleList<Tr>::insert(T n){
	Node<T>** p;
	if ( find(n,p) ) return 0;

	Node<T>* new_node=new Node<T>(n);
	
	if (*p){
		new_node->set_prev(*p);
		new_node->set_next((*p)->get_next());
		(*p)->set_next(new_node);

		if (new_node->get_next() != 0){
			(new_node->get_next())->set_prev(new_node);
		}
	} else
	{
		(*p) = new_node;
		head = new_node;
	}

	//new_node->set_next(*p);
	/*
	if ( *p ){
		new_node->set_prev((*p)->get_prev());}

	if (new_node->get_prev() == 0){
		head = new_node;
	}

	if (new_node->get_next() == 0){
		tail->set_prev(new_node);
		new_node->set_next(tail);
	}
	(*p)=new_node*/
}

template < class Tr >
bool DoubleList<Tr>::remove(T n){
	Node<T>** p;
	if (!find(n,p)) return 0;
	Node<T>* to_delete = *p;
	
	((*p)->get_prev())->set_next( (*p)->get_next() );
	((*p)->get_next())->set_prev( (*p)->get_prev() );
	(*p) = (*p)->get_next();
	
	delete to_delete;

	return 1;
}

template < class Tr >
int DoubleList<Tr>::get_size(){
	int size = 0;
	Node<T>* p=head;
	while ( *p ){
		p=p.getNext();
		size++;
	}
	return size;
}

template < class Tr >
void DoubleList<Tr>::print(){
	if(get_size()==0){
		cout<<"La lista está vacía"<<endl;
	} else{
		//iterator
	}
}

template < class Tr >
DoubleListIterator<Tr> DoubleList<Tr>::begin(){
	return iterator(head);
}

template < class Tr >
DoubleListIterator<Tr> DoubleList<Tr>::end(){
	return iterator(0);
}