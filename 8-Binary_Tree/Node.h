template <class T>
class Node
{
private:
	T data;
public:
	Node<T> *leaf[2];

	Node(T n){
		data = n;
		leaf[0] = leaf[1] = 0;
	}

	void set_data(T new_data){
		data = new_data;
	}

	T get_data(){
		return data;
	}
};