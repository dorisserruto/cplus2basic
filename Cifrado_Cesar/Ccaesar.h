#pragma once
#include <iostream>
#include <fstream>

using namespace std;

ref class Ccaesar
{
public:
	int iclaveCesar;
	char cAlfabeto[27];

	Ccaesar(void);
	Ccaesar(int iclave);

	char* cifrar(string stexto);
	int obtenerPosicion (char cletra);
};
