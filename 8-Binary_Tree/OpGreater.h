template <class T>
class OpGreater
{
public:
	bool operator ()(T first, T second){
		return (first > second);
	}
};