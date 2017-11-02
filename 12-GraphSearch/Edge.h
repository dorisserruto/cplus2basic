template < class G >
class Edge{
public:
	typedef typename G::Node Node;
	typedef typename G::E E;
private:
	E data;
	bool direction;
public:
	Node* nodes[2];

	Edge(Node* start, Node* end, E new_data, bool dir){
		data = new_data;
		node[0] = begin;
		node[1] = end;
		direction = dir;
	}

	E get_data(){
		return data;
	}
	bool get_direction(){
		return direction;
	}
};