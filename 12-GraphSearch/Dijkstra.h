template < class G >

class Dijkstra{
	typedef typename NN N;
	typedef typename EE E;
	typedef typename Node< self > Node;
	typedef typename Edge< self > Edge;
	typedef typename list< Node* > NodeSeq;
	typedef typename list< Edge* > EdgeSeq;

	typedef typename NodeSeq::iterator niterator;
	typedef typename EdgeSeq::iterator eiterator;

	void dijkstra_search(Node* node_start, Node* node_end, NodeSeq*& path){
		int sum = 0;
		int partial_sum = 0;
		Node* partial_node;

		dijkstra_short_path(node_start, partial_node, partial_sum);

		while (partial_node != 0){
			if (partial_node != node_end){
				sum = sum + partial_sum;

				dijkstra_short_path(node_start, partial_node, partial_sum);
			}
		}
	}

	void dijkstra_short_path(Node* start, Node*& selected, int& partial){
		int weight = 0;
		eiterator j;
		
		weight =(*j)->get_data();

		for (j= start->edges.begin(); j != start->edges.end(); j++){
			if ( (*j)->get_data() + weight < partial + weight ){
				weight = (*j)->get_data();
				selected = (*j)->nodes[1];
			}
		}
	}
};