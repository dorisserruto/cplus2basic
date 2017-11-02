template < class T >
class Node
{
public:
	T data;
	Node<T>* prev;
	Node<T>* next;

	Node(T n){
		data = n;
		prev = 0;
		next = 0;
	}

	T get_data(){
		return data;
	}

	void set_next(Node<T>* new_next){
		next = new_next;
	}

	void set_prev(Node<T>* new_prev){
		prev = new_prev;
	}

	Node<T>* get_next(){
		return next;
	}

	Node<T>* get_prev(){
		return prev;
	}
};