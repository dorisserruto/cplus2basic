#ifndef CFEISTEL_H_INCLUDED
#define CFEISTEL_H_INCLUDED


#include <iostream>
#include <string>

using namespace std;

class cfeistel{
public:
    cfeistel(int iclave);
	virtual ~cfeistel();

	int iclaveFeistel;
	string sAlfabeto;

	string cifrar(string stexto);
	string descifrar(string stexto, string sclave);

    int obtenerPosicion (char cletra);
};
#endif // CFEISTEL_H_INCLUDED
