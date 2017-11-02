#include "Edge.h"

template < class NN, class EE >
class Graph
{
	typedef typename Graph<NN,EE> self;
	typedef typename NN N;
	typedef typename EE E;
	typedef typename Node<self> Node;
	typedef typename Edge<self> Edge;

	Graph(){}
};