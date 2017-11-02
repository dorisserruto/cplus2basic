#include <iostream>

#include "Node.h"
#include "Edge.h"
#include "GraphIterator.h"
#include "Dijkstra.h"

using namespace std;

template < class NN, class EE >
class Graph{
public:
	typedef typename Graph< NN,EE > self;
	typedef typename NN N;
	typedef typename EE E;

	typedef typename Node< self > Node;
	typedef typename Edge< self > Edge;

	typedef typename list< Node* > NodeSeq;
	typedef typename list< Edge* > EdgeSeq;

	typedef typename NodeSeq::iterator niterator;
	typedef typename EdgeSeq::iterator eiterator;

	NodeSeq nodes;

	Graph(){}



	bool insert_node(N data){
		Node* new_node = new Node(data);
		nodes.push_back(new_node);
		return true;
	}

	bool insert_edge(Node* start, Node* end, E data, bool dir){
		Edge< E > new_edge = new Edge< E >(start,end,data,dir);

		start->add_Edge(new_edge);
		end->add_Edge(new_edge);
		return true;
	}

	void print_Graph(){
		niterator i;
		eiterator j;

		for (i = nodes.begin(); i != nodes.end(); i++){
			cout<<(*i)->get_data()<<endl;
			for (j= (*i)->edges.begin(); j != (*i)->edges.end(); j++){
				cout<<(*j)->get_data()<<endl;
			}
		}
	}
};