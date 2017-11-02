#include "StdAfx.h"
#include "Ccaesar.h"

Ccaesar::Ccaesar(void)
{
}
Ccaesar::Ccaesar(int iclave){
	
	iclaveCesar = iclave;
	cAlfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}
char* Ccaesar::cifrar (string stexto){
	char* scodificado;
	int ipos_original;
	int ipos_cesar;

	for (int i = 0; i < stexto.length(); i++)
	{
		ipos_original = obtenerPosicion(stexto[i]);
		ipos_cesar = ipos_original + iclaveCesar;
		cout<<cAlfabeto[ipos_cesar];
	}
	return scodificado;
}

int Ccaesar::obtenerPosicion (char cletra){
	for (int i = 0; i < 26; i++)
	{
		if (cAlfabeto[i] == cletra){
			return i;
		}
	}
	return (-1);
}
