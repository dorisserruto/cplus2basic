#include <iostream>
#include "CList.h"
#include "CLess.h"
#include "CGreater.h"

using namespace std;

int main()
{	
	CList <int,CLess<int>> l;

	cout << "Lista Enlazada" << endl;
	return 0;
}