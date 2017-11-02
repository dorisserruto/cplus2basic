#include "OpLess.h"
#include "OpGreater.h"
#include "OpInOrder.h"

class TreeTraits
{
public:
	typedef int T;
	typedef OpLess<int> Op;
	typedef OpInOrder OpI;

	TreeTraits(){}
};