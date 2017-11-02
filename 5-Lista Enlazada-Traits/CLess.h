template <class T>
class CLess
{
	bool operator() (T a, T b)
	{
		return a < b;
	}
};