#include <iostream>
#include <cstdlib>
#include <vector>

#include "time.h"

using namespace std;

/* ** MCD (Algoritmo_BinaryGcd) ** */
int MCD(int inumMayor,int inumMenor){
    if (inumMenor > inumMayor){
        return MCD(inumMenor,inumMayor);
    }
    if (inumMenor == 0){
        return inumMayor;
    }
    if ((inumMayor % 2 == 0) && (inumMenor % 2 == 0)){
        return 2 * MCD(inumMayor/2, inumMenor/2);
    }
    if ((inumMayor % 2 == 0) && (inumMenor % 2 == 1)){
        return MCD(inumMayor/2, inumMenor);
    }
    if ((inumMayor % 2 == 1) && (inumMenor % 2 == 0)){
        return MCD(inumMayor, inumMenor/2);
    }
    else{
        return MCD((inumMayor - inumMenor)/2, inumMenor);
    }
}

/* ** RANDOM ** */
int random(int min, int max){
    int aux;
    if ( max < min ){
        aux = max;
        max = min;
        min = aux;
    }
    return ((rand()%(max-min+1))+min);
}

/*  Algoritmo extendido de Euclides */
// Sólo retorna el inverso del inumA
int Extendido_Euclides (int inumA,int inumB){
    int inumU = 1;
    int inumG,inumY;
    int inumX = 0;

    int inumT, inumS, inumV = 0;

    vector <int> inumQ;

    inumG = inumA;
    inumY = inumB;

    while (inumY != 0){
        inumQ.push_back(inumG/inumY);//Q = G/Y;
        inumT = inumG%inumY; //RESTO

        inumS = inumU - (inumQ.back() * inumX);
        inumU = inumX;
        inumG = inumY;

        inumX = inumS;
        inumY = inumT;
    }

    if (inumY == 0){
        inumV = (inumG - (inumA * inumU))/inumB;
        return inumU;
    }
}

/* ** Inversa de modulo n** */
int InversaMod (int inumero, int imodulo){
    int iinverso = 0;

    if (MCD(inumero,imodulo) != 1){
        cout<<"El número ingresado no tiene inverso"<<endl;
        return 0;
    }

    iinverso =  Extendido_Euclides(inumero,imodulo);
    if (iinverso < 0){
        iinverso = imodulo+iinverso;
    }
    return iinverso;
}
/* Exponenciacion Modular */
int Exponencia_Modular (int ip,int iexp, int imod){
    int n = iexp;
    int exp = 1;
    int x = ip % imod;
    while (n > 0){
        if (n % 2 != 0)
            exp = (exp * x) % imod;
        x = (x*x) % imod;
        n = n/2;
    }
    return exp;
}


int Teorema_Resto_Chino(){

}

/*  R S A: GENERAR CLAVE PRIVADA Y PUBLICA */
void RSAGenerarClaves (int iprimoP, int iprimoQ){
    int N = 0;
    int phiN = 0;
    int E = 0;
    int iMCD = 0;
    int D = 0;

    //obtener n
    N = iprimoP * iprimoQ;
    //obtener phi de n
    phiN = (iprimoP - 1)*(iprimoQ - 1);
    //selecccionar e
    while (iMCD != 1){
        srand(time(NULL));
        E = rand()% phiN; //selecciono un numero entre 0 y phiN
        iMCD = MCD (E, phiN);
    }
    //encontrar d
    D = InversaMod (E, phiN);

    cout<<"Valor de N: "<<N<<endl;
    cout<<"Valor de phiN: "<<phiN<<endl;
    cout<<"Valor de iMCD: "<<iMCD<<endl;
    cout<<"Valor de D: "<<D<<endl;
    cout<<"Valor de E: "<<E<<endl;
}

/*  Obtener posicion segun alfabeto definido */
int obtenerPosicion (char cletra){
    string sAlfa = "abcdefghijklmnñopqrstuvwxyz";
	for (int i = 0; i < (sAlfa.length() + 1); i++){
		if (sAlfa[i] == cletra){
			return i;
		}
	}
	return (-1);
}

/* R S A : CIFRAR MENSAJE: USANDO CLAVE PUBLICA */
string CifrarRSA(int claveE, int claveN, string smsj){

    //string sAlfabeto = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZáéíóúÁÉÍÓÚ,;:.-_/¿?¡!&=\"* 0123456789";
    string sAlfa = "abcdefghijklmnñopqrstuvwxyz";

    //Utilizando bloques de 2 letra
    string scifrado;
    int Pmsj = 0;
    int Qmsj = 0;

	for (int i = 0; i < smsj.length(); i++)
	{
		// Asignar a cada letra su posición segun alfabeto
		Pmsj = obtenerPosicion(smsj[i]);
		// Realizar cifrado utilizando exponencia modular
		Qmsj = Exponencia_Modular(Pmsj,claveE,claveN);
		//Concatenar cada uno de los caracteres cifrados
		scifrado = scifrado+ sAlfa[Qmsj];
	}
	cout<<"El archivo fue cifrado"<<endl;
	return scifrado;
}

int main()
{
    cout<< "Prueba RSA" << endl;
    RSAGenerarClaves(17,7);
    cout<<InversaMod(35,3);
    cout<<Exponencia_Modular(549,101,731)<<endl;
    cout<<CifrarRSA(7,33,"si");

    return 0;
}

