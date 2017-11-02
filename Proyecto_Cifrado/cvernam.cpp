#include <stdlib.h> //rand() y srand()
#include <string>

#include "cvernam.h"
#include "lector.h"

cvernam::cvernam()
{
    sAlfabeto = "abcdefghijklmnÒopqrstuvwxyzABCDEFGHIJKLMN—OPQRSTUVWXYZ·ÈÌÛ˙¡…Õ”⁄,;:.-_/ø?°!&=\"* 0123456789";
}

cvernam::~cvernam()
{
}

string cvernam::cifrar(string stexto){

    string scodificado;
    string sclaveGen;

    lector l_clave;

    int itam_texto = 0;
    int iposicion = 0;
    int iposCif = 0;

    string sbinMsj = "";
    string sbinClv = "";
    string sxorCif = "";

    //Generar la clave para el texto
    itam_texto = stexto.length();
    sclaveGen = generarClave(itam_texto);

    //Escribir la clave generada en un archivo
    l_clave.escribirArchivo("clave_vernam.txt",sclaveGen);

    for ( int i = 0; i < itam_texto; i++){
        // Mensaje original
        iposicion = obtenerPosicion(stexto[i]);
        sbinMsj = aBinario7(iposicion);

        //Clave generada
        iposicion = obtenerPosicion(sclaveGen[i]);
        sbinClv = aBinario7(iposicion);

        //Aplica XOR de BinMsj y BinClave
        sxorCif = XOR7(sbinMsj,sbinClv);

        //Obtiene el decimal del binario obtenido por XOR
        iposCif = aDecimal7(sxorCif);

        //Obtenemos la letra/caracter correspondiente
        if (iposCif > 91){
            iposCif = iposCif - 92;
        }
        scodificado = scodificado + sAlfabeto[iposCif];

        cout<<sAlfabeto[iposCif];
	}
	cout<<endl;
    return scodificado;
}

string cvernam::descifrar(string stexto, string sclave){

    string sdecodificado;

    int itam_texto = 0;
    int iposicion = 0;
    int iposCif = 0;

    string sbinCif = "";
    string sbinClv = "";
    string sxorMsj = "";

    itam_texto = stexto.length();

    for ( int i = 0; i < itam_texto; i++){
        // Mensaje cifrado
        iposCif = obtenerPosicion(stexto[i]);
        sbinCif = aBinario7(iposCif);

        //Clave recibida
        iposCif = obtenerPosicion(sclave[i]);
        sbinClv = aBinario7(iposCif);

        //Aplica XOR de BinMsj y BinClave
        sxorMsj = XOR7(sbinCif,sbinClv);

        //Obtiene el decimal del binario obtenido por XOR
        iposicion = aDecimal7(sxorMsj);

        //Obtenemos la letra/caracter correspondiente
        if (iposicion > 91){
            iposicion = iposicion - 92;
        }
        sdecodificado = sdecodificado+ sAlfabeto[iposicion];
	}
    return sdecodificado;
}

int cvernam::obtenerPosicion (char cletra){
	for (int i = 0; i < (sAlfabeto.length() + 1); i++)
	{
		if (sAlfabeto[i] == cletra){
			return i;
		}
	}
	return (-1);
}

string cvernam::aBinario7(int ipos){

    string stemp;
    string sbin;

    int idiv = -1;
    int imod = -1;
    int i = 0;

    idiv = ipos;

    while (idiv != 0){
        imod = idiv%2;
        if (imod == 1)
            stemp += "1";
        else
            stemp += "0";
        idiv = idiv / 2;
        i++;
    }
    for (;i<7;i++){
        stemp += "0";
    }

    for (int i = 0, j = 6; i<8; i++){
        sbin+= stemp[j-i];
    }
    return sbin;
}

int cvernam::aDecimal7(string spos){
    int idecimal = 0;
    int inum = 0;

    for (int i = 6; i >= 0; i--){
        inum = (spos[i] - '0');
        if (inum == 1){
            idecimal += potencia(2,(6-i));
        }
    }
    return idecimal;
}

string cvernam::XOR7(string ip, string iq){
    string sxor;

    for (int i = 0; i < 7; i++){
        if (ip[i] == iq[i]){
            sxor = sxor + '0';
        }
        else{
            sxor = sxor + '1';
        }
    }
    return sxor;
}
string cvernam::generarClave(int itam){
    int inum = 0;
    string sclave;

    //Generar numero aleatorio para crear mensaje
    for (int i = 0; i < itam; i++){
        //srand ((unsigned)time(0));
        //inum = rand() % 92 + 0;
        inum = random(0,92);

        sclave = sclave+sAlfabeto[inum];
    }
    return sclave;
}

int cvernam::potencia(int base, int exp)
{
        if (exp <= 0)
            return 1;
        else
            return base*potencia(base,exp-1);
}

//Gracias a: eagleoneraptor (http://www.elrincondelc.com/nuevorincon/foros/viewtopic.php?t=9155)
int cvernam::random( int min, int max)
{
    int aux;
    if ( max < min ){
        aux = max;
        max = min;
        min = aux;
    }
    return ((rand()%(max-min+1))+min);
}
