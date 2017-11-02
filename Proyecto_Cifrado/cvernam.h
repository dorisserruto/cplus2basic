#ifndef CVERNAM_H_INCLUDED
#define CVERNAM_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class cvernam{
public:
    cvernam();
	virtual ~cvernam();

	string sVigClave;
	string sAlfabeto;

	string cifrar(string stexto);
	string descifrar(string stexto, string sclave);

    int obtenerPosicion (char cletra);

    string aBinario7(int ipos);
    int aDecimal7(string spos);
    string XOR7(string ip, string iq);

    string generarClave(int itam);
    int potencia(int base, int exp);

    int random(int min,int max);
    //1111111 = 127 -- 1011100 = 92

};

#endif // CVERNAM_H_INCLUDED
