#include <time.h>
#include <stdlib.h>
#include <stack>

#include "TreeIterator.h"
#include "TIPair.h"

using namespace std;

template < class Tr >
class BinaryTree
{
public:
	typedef typename Tr::T T;
	typedef typename Tr::Op Op;
	typedef typename Node<T> Node;
	typedef typename TreeIterator<T> iterator;

	Node* root;

	BinaryTree(){
		root = 0;
	}

	Node** find_reemplace(Node** p){
		srand(time(null));
		bool r = rand()%2;

		Node** q = p;
		q = &( (*q)->leaf[r]);
		while ( (*q)->leaf[!r] ){
			q = &( (*q)->leaf[!r] );
		}
		return q;
	}
	bool find(T n, Node**& p);
	bool insert(T n);
	bool remove (T n);

	void in_order(Node* p);
	void pre_order(Node* p);
	void post_order(Node* p);

	/*---- Iterator ----*/
	stack< TIPair<T>> leftList;
	
	iterator begin(){
		Node<T>* p = root;
		if (!p) return iterator(0);
		while (p){
			TIPair<T> pt(p,0);
			leftList.push(pt);
			p = p->leaf[0];
		}
		return iterator(leftList.top()->point);
	}

	iterator end(){
		return iterator(0);
	}
};

template < class Tr >
bool BinaryTree<Tr>::find(T n, Node**& p)
{
	p = &root;
	while (*p && (*p)->get_data() !=n)
	{
		p = &( (*p)->leaf[Op()((*p)->get_data(), n)] );
	}
	//for( p=&root; p* && (*p)->data != n; p=&( (*p)->leaf[Cmp((*p)->data, n)] ));
	return !!(*p);
}

template < class Tr >
bool BinaryTree<Tr>::insert(T n)
{
	Node** p;
	if (find(n,p)) return 0;
	(*p) = new Node(n);

	return 1; 
}

template < class Tr >
bool BinaryTree<Tr>::remove(T n)
{
	Node** p,** q;
	if (!find(n,p)) return 0;

	bool left = !!(*p)->leaf[0];
	bool right = !!(*p)->leaf[1];

	//Second Case
	if (left & right){
		q = find_reemplace(p);
		(*p)->data = (*q)->data;
		p = q;

		left = !!(*p)->leaf[0];
		right = !!(*p)->leaf[1];
	}
	//First Case
	if (left | right){
		Node* t = *p;
		*p = (*p)->leaf[right];
		delete t;
	}
	//Zero Case
	else{
		delete (*p);
		(*p) = 0;
	}
	return 1;
}

template < class Tr >
void BinaryTree<Tr>::in_order(Node* p){
	if (!p) return;
	in_order( p->leaf[0]);
	cout<< p->get_data()<<endl;
	in_order (p->leaf[1]);
}

template < class Tr >
void BinaryTree<Tr>::pre_order(Node* p){
	if (!p) return;
	cout<< p->get_data()<<endl;
	pre_order( p->leaf[0]);
	pre_order (p->leaf[1]);	
}

template < class Tr >
void BinaryTree<Tr>::post_order(Node* p){
	if (!p) return;
	post_order( p->leaf[0]);
	post_order (p->leaf[1]);
	cout<< p->get_data()<<endl;
}
