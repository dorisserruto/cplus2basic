#include <queue>
#include <boost/thread.hpp>

//#include "functionHeavy.h"
using namespace std;

template <class T, class Op>
class ThreadingFor
{
private:
	int nProcessors;

public:
	ThreadingFor();
	//ThreadingForTF(vector<T> group, Op operation, int nroThreads)
	//void ThreadingForTF(queue<T> group, Op operation)
	void ThreadingForTF(queue<T> group)
	{
		//Obtener la cantidad de procesadores disponibles
		nProcessors = boost::thread::hardware_concurrency();
		Op thisFunctionHeavy(&group);
		//Crear tantos threads como procesadores
		for (int i = 0; i <= nProcessors; i++)
			boost::thread(thisFunctionHeavy);
	}
};