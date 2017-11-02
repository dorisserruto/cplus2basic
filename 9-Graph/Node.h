#include <vector>

using namespace std;

template < class G >
class Node
{
public:
	typedef typename G::Edge Edge;
	typedef typename G::N N;

	N data;
	vector<Edge*> edges;
};