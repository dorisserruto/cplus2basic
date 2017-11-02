#include <list>
using namespace std;

template < class G >
class Node{
public:
	typedef typename G::Edge Edge;
	typedef typename G::N N;
	typedef typename list< Edge* > EdgeSeq;
private:
	N data;

public:
	EdgeSeq edges;

	Node(N new_data){
		data = new_data;
	}
	N get_data(){
		return data;
	}
	bool add_Edge(Edge* e){
		edges.push_back(e);
	}
};