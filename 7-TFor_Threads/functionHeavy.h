//Function Object que se usará con los procesos
#include <queue>
using namespace std;

template <class T>
class functionHeavy
{
private:
	int procWeight;
	queue<T> *qProc;
public:
	functionHeavy(queue<T> *procesos){
		qProc = procesos;
	}
	void operator()(){
		while (!qProc.empty()){
			heavyN3(qProc.front().getWeight());
			cout<<"Proceso:"<<qProc.front().getWeight()<<end;
			qProc.pop();
		}
	}
	void heavyN3(int weight){
		int totalCycle;
		for (int i = 0; i < weight; i++)
			for (int j = 0; j < weight; j++)
				for (int k = 0; k < weight; k++)
					totalCycle += weight;
	}

};