template < class Tr >
class DoubleListIterator
{
public:
	typedef typename DoubleListIterator<Tr> self;
	typedef typename Tr::T T;

	Node<T>* i;

	DoubleListIterator(){
		i=0;
	}

	DoubleListIterator(Node<T>* p){
		i = p;
	}

	self operator =(self& r){
		i = r.i;
		return *this;
	}

	bool operator !=(self& r){
		return (i != r.i); 
	}

	self operator ++(){
		Node<T>* p = i;
		if (i != 0){
			i=i->get_next();
		}
		return self(p);
	}

	self operator --(){
		Node<T>* p = i;
		if (i != 0){
			i=i->get_prev();
		}
		return self(p);
	}

	T operator *(){
		return i->get_data();
	}
};