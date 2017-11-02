// Ccaesar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ccaesar1.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	int clave;
	string mensaje;

	cout<< "Ingrese clave";
	cin >> clave;
	cout<<"Ingrese mensaje";
	cin >> mensaje;

	ccaesar a(clave);

	return 0;
}
