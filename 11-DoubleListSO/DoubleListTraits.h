#include "OpLess.h"
#include "OpGreater.h"

class DoubleListTraits
{
public:
	typedef int T;
	typedef OpLess<int> Op;
};