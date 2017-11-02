#include "cfeistel.h"

cfeistel::cfeistel(int iclave){

    iclaveFeistel = iclave;
	sAlfabeto = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZáéíóúÁÉÍÓÚ,;:.-_/¿?¡!&=\"* 0123456789"; //92
}

cfeistel::~cfeistel(){

}

string cfeistel::cifrar(string stexto){
    /*string sTextoA;
    string sTextoB;

    int itamTexto = 0;
    itamTexto = strlen(stexto);

    for (int i = 0; i<(itamTexto/2);*/


}
string cfeistel::descifrar(string stexto, string sclave){

}

int cfeistel::obtenerPosicion (char cletra){
    for (int i = 0; i < (sAlfabeto.length() + 1); i++)
	{
		if (sAlfabeto[i] == cletra){
			return i;
		}
	}
	return (-1);
}
