#include <iostream>
#include <queue>

#include <time.h>
#include <stdlib.h>

#include "Process.h"
#include "ThreadingFor.h"
#include "functionHeavy.h"

using namespace std;

//1. Genera una lista de procesos
queue<Process> generateProcess(int lowRange, int topRange, int quantity)
{
	int randomValue;
	queue <Process> vProcess;
	srand((unsigned int)(time(NULL)));

	for (int i= 0; i < quantity; i++){
		randomValue = lowRange + (rand()%topRange);

		Process newProcess(randomValue);
		vProcess.push(newProcess);
	}
	return vProcess;
}


//int main(int argc, char* argv[])
int main()
{
	queue<Process> myProcess = generateProcess(10000,50000,1000);
	ThreadingFor<Process,functionHeavy<Process>> TF;
	
	TF.ThreadingForTF(myProcess);

	return 0;
};