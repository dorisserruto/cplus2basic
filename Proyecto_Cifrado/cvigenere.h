#ifndef CVIGENERE_H_INCLUDED
#define CVIGENERE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class cvigenere
{
public:
	cvigenere();
	cvigenere(string sclave);
	virtual ~cvigenere();

	string sVigClave;
	string sAlfabeto;

	string cifrar(string stexto);
	string descifrar(string stexto);
    int obtenerPosicion (char cletra);
};

#endif // CVIGENERE_H_INCLUDED
