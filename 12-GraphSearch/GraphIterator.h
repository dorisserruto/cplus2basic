template < class G >
class GraphIterator{
public:
	typedef typename G::NN N;
	typedef typename GraphIterator< G > self;
	typedef typename Node< G > Node;

	Node* i;

	GraphIterator(Node* i){
		this.i = i;
	}
	
	self operator = (self &r){
		this.i = r.i;
		return *this;
	}

	bool operator != (self &r){
		return (this.i != r.i);
	}

	N operator *(){
		return this.i->data;
	}

	self operator ++(){
		
	}
};