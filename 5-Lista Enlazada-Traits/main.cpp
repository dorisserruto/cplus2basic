#include <iostream>
#include "CList.h"
#include "CLess.h"
#include "CGreater.h"

using namespace std;

int main(int argc, char* argv[])
{	
	CList <int,CLess<int>> l();

	cout << "Lista Enlazada" << endl;
	return 0;
}