template < class T >
class OpLess
{
public:
	bool operator() (T first, T second){
		return (first < second);
	}
};