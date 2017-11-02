#include "cvigenere.h"

cvigenere::cvigenere()
{
	sAlfabeto = "abcdefghijklmnÒopqrstuvwxyzABCDEFGHIJKLMN—OPQRSTUVWXYZ·ÈÌÛ˙¡…Õ”⁄,;:.-_/ø?°!&=\"* 0123456789";
}

cvigenere::cvigenere(string sclave)
{
    sVigClave = sclave;
	sAlfabeto = "abcdefghijklmnÒopqrstuvwxyzABCDEFGHIJKLMN—OPQRSTUVWXYZ·ÈÌÛ˙¡…Õ”⁄,;:.-_/ø?°!&=\"* 0123456789";
}

cvigenere::~cvigenere()
{

}

string cvigenere::cifrar(string stexto){
    string scodificado;
	int itam_texto= 0;
	int itam_clave= 0;

	int inuevapos = 0;

	itam_texto = stexto.length();
	itam_clave = sVigClave.length();

	for ( int i = 0, j = 0; i < itam_texto; i++){
        inuevapos = obtenerPosicion(stexto[i]) + obtenerPosicion(sVigClave[j]);
        if (inuevapos > 91){
            inuevapos = inuevapos - 92;
        }
        scodificado = scodificado + sAlfabeto[inuevapos];
	    j++;
	    if (j == itam_clave){ j = 0;}
	}
	return scodificado;
}

string cvigenere::descifrar(string stexto){
    string sdecodificado;
	int itam_texto= 0;
	int itam_clave= 0;

	int inuevapos = 0;

	itam_texto = stexto.length();
	itam_clave = sVigClave.length();

	for ( int i = 0, j = 0; i < itam_texto; i++){
        inuevapos = obtenerPosicion(stexto[i]) - obtenerPosicion(sVigClave[j]);
        if (inuevapos < 0){
				inuevapos = inuevapos + 92;
		}
        sdecodificado = sdecodificado + sAlfabeto[inuevapos];
	    j++;
	    if (j == itam_clave){ j = 0;}
	}
	return sdecodificado;
}

int cvigenere::obtenerPosicion (char cletra){
	for (int i = 0; i < (sAlfabeto.length() + 1); i++)
	{
		if (sAlfabeto[i] == cletra){
			return i;
		}
	}
	return (-1);
}
