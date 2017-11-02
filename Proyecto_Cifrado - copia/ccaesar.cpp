#include "ccaesar.h"


ccaesar::ccaesar(int iclave){

	iclaveCesar = iclave;
	cAlfabeto = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZáéíóúÁÉÍÓÚ,;:.-_/¿?¡!&=\"* 0123456789"; //91
	//cAlfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ., abcdefghijklmnopqrstuvwxyzáéíóú";
}

ccaesar::~ccaesar()
{
}

string ccaesar::cifrar (string stexto){
	string scodificado;
	int ipos_original;
	int ipos_cesar;

	for (int i = 0; i < stexto.length(); i++)
	{
		ipos_original = obtenerPosicion(stexto[i]);
		ipos_cesar = ipos_original + iclaveCesar;

		if (ipos_cesar > 91){
				ipos_cesar = ipos_cesar - 92;
		}
		scodificado = scodificado + cAlfabeto[ipos_cesar];
	}
	cout<<"El archivo fue cifrado"<<endl;
	return scodificado;
}

string ccaesar::descifrar (string stexto){
	string sdecodificado;
	int ipos_original;
	int ipos_cesar;

	for (int i = 0; i < stexto.length(); i++)
	{
		ipos_original = obtenerPosicion(stexto[i]);
		ipos_cesar = ipos_original - iclaveCesar;

		if (ipos_cesar < 0){
				ipos_cesar = ipos_cesar + 92;
		}
		sdecodificado = sdecodificado + cAlfabeto[ipos_cesar];
	}
	cout<<"El archivo fue descifrado"<<endl;
	return sdecodificado;
}

int ccaesar::obtenerPosicion (char cletra){
	for (int i = 0; i < (cAlfabeto.length() + 1); i++)
	{
		if (cAlfabeto[i] == cletra){
			return i;
		}
	}
	return (-1);
}
