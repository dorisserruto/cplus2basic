//#include "Node.h"

template <class T>
class TIPair{
public:
	Node<T> *point;
	int state;

	TIPair(Node<T> *p, int s)
	{
		point = p;
		state = s;
	}
};