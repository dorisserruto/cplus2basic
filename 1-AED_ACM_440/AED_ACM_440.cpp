// AED_ACM_440.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <ios>
#include <stack>

using namespace System;

int minimalNumber (int icities)
{
	stack <int> cities;

	//1.Llenamos la pila con los nros de ciudades
	for (int i = 0; i <= icities; i++)
	{
		cities.push(i);
	}
	//2. Pro
}

int main(array<System::String ^> ^args)
{
	int iciudades;
	int iminimal;

	cout>>"Ingrese numero de ciudades";
	cin>>iciudades;

	iminimal = minimalNumber (iciudades);

	cout>>"El numero minimo es: "+ iminimal;
    return 0;
}
