#include <iostream>

#include "Node.h"
#include "DoubleListIterator.h"

using namespace std;

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
	void inverse_print();
	iterator begin();
	iterator end();

	iterator r_begin();
	iterator r_end();
	friend class Node<T>;
};

template < class Tr >
bool DoubleList<Tr>::find(T n, Node<T>**& p){
	p = &head;

	while ( *p && Op()((*p)->get_data(),n) ){
		Node<T>* new_next = (*p)->get_next();
		p = &(new_next);
	}
	if ( (*p) != 0 && (*p)->get_data() == n ){
		return true;
	}
	return false;
}

template < class Tr >
bool DoubleList<Tr>::insert(T n){
	Node<T>** p;
	if ( find(n,p) ) return 0;

	Node<T>* new_node=new Node<T>(n);
	
	if (*p){
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	} else
	{
		(*p) = new_node;
		head = new_node;
		tail = new_node;
	}
}

template < class Tr >
bool DoubleList<Tr>::remove(T n){
	Node<T>** p;
	if (!find(n,p)) return 0;

	Node<T>* to_delete = *p;

	//-((*p)->get_prev())->set_next((*p)->get_next());
	//-((*p)->get_next())->set_prev((*p)->get_prev()); //la misma logica pero no funciona
	( (*p)->prev )->next = (*p)->next;
	( (*p)->next )->prev = (*p)->prev;
	
	(*p) = (*p)->get_next();
	delete to_delete;

	return 1;
}

template < class Tr >
int DoubleList<Tr>::get_size(){
	int size = 0;
	Node<T>* p=head;
	while (p){
		p=p->get_next();
		size++;
	}
	return size;
}

template < class Tr >
void DoubleList<Tr>::print(){
	if(get_size()==0){
		cout<<"La lista está vacía"<<endl;
	} else{
		for(iterator i=begin(); i != end(); ++i)
		{
			cout<<(*i)<<endl;
		}
	}
}

template < class Tr >
void DoubleList<Tr>::inverse_print(){
	if(get_size()==0){
		cout<<"La lista está vacía"<<endl;
	} else{
		for(iterator i=r_begin(); i != r_end(); --i)
		{
			cout<<(*i)<<endl;
		}
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

template < class Tr >
DoubleListIterator<Tr> DoubleList<Tr>::r_begin(){
	return iterator(tail);
}
template < class Tr >
DoubleListIterator<Tr> DoubleList<Tr>::r_end(){
	return iterator(0);
}