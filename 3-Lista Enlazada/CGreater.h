template <class T>
class CGreater
{
	bool operator() (T a, T b)
	{
		return a > b;
	}
};