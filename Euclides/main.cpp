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

    if ((inumMayor < 0) && (inumMenor < 0)){
        cout<<"Algunos de los valores es zero o negativo"<<endl;
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

    if ((inumMayor < 0) && (inumMenor < 0)){
        cout<<"Algunos de los valores es zero o negativo"<<endl;
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
    if (inumMenor == 0){
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

int  Alg_Extendido_Euclides (int inumA,int inumB){
    int inumU = 1;
    int inumG,inumY;
    int inumX = 0;

    int inumT, inumS, inumV = 0;

    //int * iRespuesta = new int[3];
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
        /*iRespuesta[0] = inumG; //G
        iRespuesta[1] = inumU; //U
        iRespuesta[2] = inumV; //V*/

        //cout<<"G="<<inumG<<endl;
        //cout<<"U="<<inumU<<endl;
        //7cout<<"V="<<inumV<<endl;

        return inumU;
    }
}

void Alg_Extendido_EuclidesGcd (int inumK,int inumN){
    int i = 0;
    int iGCD = 0;

    vector <int> k,n,r,q,x,z;

    k.push_back(inumK);  //k[i] = inumK;
    n.push_back(inumN); //n[i] = inumN;

    do{
        q.push_back(k.back()/n.back()); //q[i] = (k[i]/n[i]);
        r.push_back(k.back() - (q.back()*n.back())); //r[i] = (k[i]-(q[i]*n[i]));
        k.push_back(n.back()); //k[i+1] = n[i];
        n.push_back(r.back()); //n[i+1] = r[i];
        i++;
    } while (r[i-1] != 0);

    i--;
    iGCD = n[i];

    x.push_back(0);
    z.push_back(1);
    i--;
    while (i >= 0){
        x[i] = z[i+1];
        z[i] = x[i+1] - (q[i]*z[i+1]);
        i--;
    }
    cout<<iGCD;
}

/* ************************************* */
 /* I N V E R S A  D E  M O D U L O  N */
/* ************************************ */
int InversaMod (int inumero, int imodulo){
    int iinverso = 0;

    if (Algoritmo_BinaryGcd(inumero,imodulo) != 1){
        cout<<"El número ingresado no tiene inverso"<<endl;
        return 0;
    }

    iinverso =  Alg_Extendido_Euclides(inumero,imodulo);
    if (iinverso < 0){
        iinverso = imodulo+iinverso;
    }
    return iinverso;
}

int main()
{
    int iNumeroA = -1;
    int iNumeroB = -1;
    int iopcion;

    cout<<"A L G O R I T M O S  D E  E U C L I D E S "<<endl;

    cout<<"1. Primer Algoritmo"<<endl;
    cout<<"2. Segundo Algoritmo"<<endl;
    cout<<"3. Algoritmo Recursivo (EuclidesMcd)"<<endl;
    cout<<"4. BinaryGcd"<<endl;
    cout<<"5. Extendido de Euclides"<<endl;
    cout<<"6. Extendido de Euclides GCD"<<endl;
    cout<<"7. Inversa de Modulo n"<<endl;
    cout<<endl;

    cout<<"Ingrese el numero de la accion deseada:"<<endl;
    cin>>iopcion;

    switch (iopcion) {
        case 1: {
            cout << "Ingrese primero numero (mayor)" << endl;
            cin >> iNumeroA;
            cout << endl;
            cout << "Ingrese segundo numero (menor)" << endl;
            cin >> iNumeroB;
            cout << endl;

            cout << "Resultado del Primer Algoritmo" << endl;
            cout<< AlgoritmoEuclides_01(iNumeroA, iNumeroB);
            cout << endl;
            break;
        }
        case 2: {
            cout << "Ingrese primero numero (mayor)" << endl;
            cin >> iNumeroA;
            cout << endl;
            cout << "Ingrese segundo numero (menor)" << endl;
            cin >> iNumeroB;
            cout << endl;

            cout << "Resultado del Segundo Algoritmo" << endl;
            cout<< AlgoritmoEuclides_02(iNumeroA, iNumeroB);
            cout<<endl;
            break;
        }
        case 3: {
            cout << "Ingrese primero numero (mayor)" << endl;
            cin >> iNumeroA;
            cout << endl;
            cout << "Ingrese segundo numero (menor)" << endl;
            cin >> iNumeroB;
            cout << endl;

            cout << "Resultado del Algoritmo Recursivo (EuclidesMcd)" << endl;
            cout<< Euclidesmcd(iNumeroA, iNumeroB);
            cout<<endl;
            break;
        }
        case 4: {
            cout << "Ingrese primero numero (mayor)" << endl;
            cin >> iNumeroA;
            cout << endl;
            cout << "Ingrese segundo numero (menor)" << endl;
            cin >> iNumeroB;
            cout << endl;

            cout << "Resultado del BinaryGcd" << endl;
            cout<< Algoritmo_BinaryGcd(iNumeroA, iNumeroB);
            cout<<endl;
            break;
        }
        case 5: {
            cout << "Ingrese primero numero (mayor)" << endl;
            cin >> iNumeroA;
            cout << endl;
            cout << "Ingrese segundo numero (menor)" << endl;
            cin >> iNumeroB;
            cout << endl;

            cout << "Resultado del Extendido de Euclides" << endl;
            Alg_Extendido_Euclides(iNumeroA, iNumeroB);
            cout<<endl;
            break;
        }
        case 6: {
            cout << "Ingrese primero numero (mayor)" << endl;
            cin >> iNumeroA;
            cout << endl;
            cout << "Ingrese segundo numero (menor)" << endl;
            cin >> iNumeroB;
            cout << endl;

            cout << "Resultado del Extendido de Euclides GCD" << endl;
            Alg_Extendido_EuclidesGcd(iNumeroA, iNumeroB);
            cout<<"-"<<endl;
            break;
        }
        case 7: {
            cout << "Ingrese numero" << endl;
            cin >> iNumeroA;
            cout << endl;
            cout << "Ingrese modulo" << endl;
            cin >> iNumeroB;
            cout << endl;

            cout << "El inverso de " << iNumeroA << " modulo de "<< iNumeroB<< " es :"<<endl;
            cout<<InversaMod(iNumeroA, iNumeroB);
            cout<<endl;
            break;
        }
    }
    return 0;
}
