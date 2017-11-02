#ifndef CCAESAR_H_INCLUDED
#define CCAESAR_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class ccaesar
{
public:
	int iclaveCesar;
	string cAlfabeto;

	ccaesar();
	ccaesar(int iclave);
	virtual ~ccaesar();

	string cifrar (string stexto);
	string descifrar (string stexto);
	int obtenerPosicion (char cletra);
};

#endif // CCAESAR_H_INCLUDED
