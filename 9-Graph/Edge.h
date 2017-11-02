#include "Node.h"

template < class G >
class Edge
{
public:
	typedef typename G::Node Node;
	typedef typename G::E E;

	E data;
	Node* nodes[2];
};