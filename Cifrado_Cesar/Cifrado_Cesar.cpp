// Cifrado_Cesar.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "Ccaesar.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	Ccaesar consulta1(5);
	char ctexto[1000];
	//int iclave_ingresada;

	cout<<"Ingrese clave"<<endl;
	//cin>>iclave_ingresada;
	cout<<"Ingrese texto a ser cifrado"<<endl;
	cin>>ctexto;
	consulta1.cifrar(ctexto);

    return 0;
}
