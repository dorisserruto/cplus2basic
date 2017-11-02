#include <iostream>
#include <vector>

using namespace std;

/* ******************************************* */
 /* A L G O R I T M O S  D E  E U C L I D E S */
/* ******************************************* */

int AlgoritmoEuclides_01(int inumMayor, int inumMenor){
    //numMayor debe ser mayor a numMenor
    int iresto = -1;
    int iteracc = 0;

    if (inumMayor < inumMenor){
        return AlgoritmoEuclides_01(inumMenor,inumMayor);
    }

    if ((inumMayor <= 0) && (inumMenor <= 0)){
        cout<<"Algunos de los valores son negativos"<<endl;
        return -1;
    }

    while ( iresto != 0 ){
        iteracc++;
        iresto = inumMayor%inumMenor;
        if (iresto == 0){
        cout<<iteracc<<endl;
        return inumMenor;
        }
        else {
            inumMayor = inumMenor;
            inumMenor = iresto;
        }
    }

}
int AlgoritmoEuclides_02(int inumMayor, int inumMenor){
    int iresto = -1;
    int iteracc = 0;

    if (inumMayor < inumMenor){
        cout<<"El primer número no es mayor al segundo número ingresado"<<endl;
        return -1;
    }

    if ((inumMayor <= 0) && (inumMenor <= 0)){
        cout<<"Algunos de los valores son negativos"<<endl;
        return -1;
    }

    while ( iresto != 0 ){
        iteracc++;
        iresto = inumMayor%inumMenor;
        if (iresto == 0){
            cout<<iteracc<<endl;
            return inumMenor;
        }
        if (iresto > inumMenor/2){iresto = inumMenor - iresto;}

        inumMayor = inumMenor;
        inumMenor = iresto;
    }
}

int Euclidesmcd (int inumMayor,int inumMenor){
    if ( inumMenor == 0){
        return inumMayor;
    }
    return Euclidesmcd( inumMenor, inumMayor%inumMenor );
}

int Algoritmo_BinaryGcd(int inumMayor,int inumMenor){
    if (inumMenor > inumMayor){
        return Algoritmo_BinaryGcd(inumMenor,inumMayor);
    }
    if (inumMenor = 0){
        return inumMayor;
    }
    if ((inumMayor % 2 == 0) && (inumMenor % 2 == 0)){
        return 2 * Algoritmo_BinaryGcd(inumMayor/2, inumMenor/2);
    }
    if ((inumMayor % 2 == 0) && (inumMenor % 2 == 1)){
        return Algoritmo_BinaryGcd(inumMayor/2, inumMenor);
    }
    if ((inumMayor % 2 == 1) && (inumMenor % 2 == 0)){
        return Algoritmo_BinaryGcd(inumMayor, inumMenor/2);
    }
    else{
        return Algoritmo_BinaryGcd((inumMayor - inumMenor)/2, inumMenor);
    }
}

/* **************************************************************** */
 /* A L G O R I T M O S  E X T E N D I D O S  D E  E U C L I D E S */
/* **************************************************************** */

/*  Algoritmo extendido de Euclides */

void  Alg_Extendido_Euclides (int inumA,int inumB){
    int inumU = 1;
    int inumG,inumY;
    int inumX = 0;

    int inumT, inumS, inumV = 0;

    int * iRespuesta = new int[3];
    vector <int> inumQ;

    inumG = inumA;
    inumY = inumB;

    while (inumY != 0){
        inumQ.push_back(inumG/inumY);//Q = G/Y;
        inumT = inumG%inumY; //RESTO

        inumS = inumU - (inumQ[1] * inumX);
        inumU = inumX;
        inumG = inumY;

        inumX = inumS;
        inumY = inumT;
    }

    if (inumY == 0){
        inumV = (inumG - (inumA * inumU))/inumB;
        /*iRespuesta[0] = inumG; //G
        iRespuesta[1] = inumU; //U
        iRespuesta[2] = inumV; //V*/

        cout<<inumG<<endl;
        cout<<inumU<<endl;
        cout<<inumV<<endl;

        //return iRespuesta;
    }
}

int main()
{
    int iNumeroA = -1;
    int iNumeroB = -1;

    cout << "A L G O R I T M O S" << endl;
    cout << "Ingrese primero numero (mayor)" << endl;
    cin >> iNumeroA;
    cout << endl;
    cout << "Ingrese segundo numero (menor)" << endl;
    cin >> iNumeroB;
    cout << endl;

    cout << "Resultado del Primer Algoritmo" << endl;
    cout<< AlgoritmoEuclides_01(iNumeroA, iNumeroB);
    cout << endl;
    cout << "Resultado del Segundo Algoritmo" << endl;
    cout<< AlgoritmoEuclides_02(iNumeroA, iNumeroB);
    cout<<endl;
    cout << "Resultado del Algoritmo Recursivo (EuclidesMcd)" << endl;
    cout<< Euclidesmcd(iNumeroA, iNumeroB);
    cout<<endl;
    cout << "Resultado del BinaryGcd" << endl;
    cout<< Algoritmo_BinaryGcd(iNumeroA, iNumeroB);
    cout<<endl;
    cout << "Resultado del Extendido de Euclides" << endl;
    Alg_Extendido_Euclides(iNumeroA, iNumeroB);
    cout<<endl;
    return 0;
}
