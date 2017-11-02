#include <iostream>
#include <vector>
//#include <list>

#include <math.h>

using namespace std;

//1. Algoritmo de Euclides
int algorithm01 (int i_num1, int i_num2)
{
    int i_resto = 0;
    i_resto = i_num1%i_num2;
    if (i_resto == 0)
    {
        return i_num2;
    }
    else
    {
        algorithm01(i_num2, i_resto);
    }
}

//2. Algoritmo de Euclides
int algorithm02 (int i_num1, int i_num2)
{
    int i_resto = 0;
    i_resto = i_num1%i_num2;
    if (i_resto == 0)
    {
        return i_num2;
    }
    else
    {
        if (i_resto > (i_num2/2))
            i_resto = i_num2 - i_resto;
        algorithm01(i_num2, i_resto);
    }
}

//3. Algoritmo de Euclides
int algorithm03(int i_num1, int i_num2)
{
    if (i_num2 == 0)
        return i_num1;
    return algorithm03(i_num2,(i_num1%i_num2));
}

// 4. Algoritmo de Euclides BinaryGCD
int algorithmBinaryGCD (int i_num1, int i_num2)
{
    int i_g = 0;
    int i_t = 0;
    while ( (i_num1 %2 ==0) && (i_num2 %2 == 0) )
    {
        i_num1 = i_num1 /2 ;
        i_num2 = i_num2 /2 ;
        i_g = 2 * i_g;
    }
    if (i_num1 != 0)
    {
        while (i_num1% 2 ==0)
        {
            i_num1 = i_num1/2;
        }
        while (i_num2% 2 ==0)
        {
            i_num2 = i_num2/2;
        }
    }
    else
    {
        i_t = (i_num1 - i_num2)/2;
        if (i_num1 >= i_num2)
        {
            i_num1 = i_t;
        }
        else
        {
            i_num2 = i_t;
        }
    }
    return (i_num2);
}

// 5. Algoritmo de Euclides GCD
int algorithmGCD (int i_num1, int i_num2)
{
    while (i_num1 != i_num2)
    {
        if (i_num1 > i_num2)
        {
            i_num1 = i_num1 - i_num2;
        }
        else
        {
            i_num2 = i_num2 - i_num1;
        }
    }
    return i_num1;
}

// 6. Algoritmo Extendido de Euclides
vector <int>  extendidoEuclides (int inumA,int inumB){
    int inumU = 1;
    int inumG,inumY;
    int inumX = 0;

    int inumT, inumS, inumV = 0;

    vector <int> inumQ;
    vector <int> viResp;

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
        viResp.push_back(inumG);
        viResp.push_back(inumU);
        viResp.push_back(inumV);

        return viResp;
    }
}

// 7. Algoritmo Extendido de EuclidesGCD
int extendidoEuclidesGCD (int inumK,int inumN){
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
    } while (r.back()!= 0); //(r[i-1] != 0);

    r.pop_back();//i--;
    iGCD = n.back();//iGCD = n[i];
    //IF(n==1)
    /*
    x.push_back(0);
    z.push_back(1);
    i--;
    while (i >= 0){
        x[i] = z[i+1];
        z[i] = x[i+1] - (q[i]*z[i+1]);
        i--;
    }
    cout<<x[0]<<"-"<<z[0]<<endl;*/
    return iGCD;
}

// 8. Determinar si un número es primo o no
bool esPrimo (int i_num)
{
    int i_resto;
    int i_numCoc = 0;
    for(int i_coc = 1;i_coc <= int(sqrt(i_num)); i_coc++)
    {
        i_resto = i_num % i_coc;
        if(i_resto ==0)
        i_numCoc++;
    }
    if (i_numCoc > 2)
        return false;
    else
        return true;
}

//9. Implementar la Criba de Erastotenes:
// Obtener primos hasta determinado numero

vector <int> cribaErastotenes (int i_num)
{
    vector <int> liImpares;
    vector <int> liPrimos;
    int i_cantPrimos = 0;

    int i_numPrimo = 0;

    //Calcular los numeros impares hastora n
    //Añadir a la lista el numero 2
    liImpares.push_back(1);
    liImpares.push_back(2);
    for (int i = 0; i < (i_num -3)/2; i++)
    {
        liImpares.push_back(2*i + 3);
    }

    //Calcular los multiplos del primer nro de la lista, a partir de 3
    // Eliminar los multiplos de la lista
    //int i_max = int(sqrt(i_num));
    for (int j= 2; j < liImpares.size(); j++)
    {
        for (int k = j; k < liImpares.size(); k++)
        {
            if ((liImpares[k] % liImpares[j] == 0) && (liImpares[k] != liImpares[j]))
                liImpares.erase(liImpares.begin()+ k);
                //cout<<(*liImpares.begin()+ k)<<endl;
        }
    }

    //int i_max = (i_num - 2)/2;
    return liImpares;
}

//Inversa en módulo N
int inversaMod (int inumero, int imodulo){
    int iinverso = 0;
    vector <int> vextendEuclides;

    if (algorithmGCD(inumero,imodulo) != 1){
        cout<<"El numero ingresado no tiene inverso"<<endl;
        return 0;
    }

    vextendEuclides =  extendidoEuclides(inumero,imodulo);
    iinverso = vextendEuclides[1];
    if (iinverso < 0){
        iinverso = imodulo+iinverso;
    }
    return iinverso;
}

// Exponenciación modular
int expMod01 ( int a, int p, int n)
{
    int r = 1;
    for (int i = 1; i< p; i++)
    {
        r = (r*a)%n;
    }
    return r;
}

int expMod02 ( int a, int p, int n)
{
    int t;
    if (p == 0)
    {
        return 1;
    }
    if (p % 2 == 0)
    {
        t = expMod02 (a, p/2, n);
        return ((t^2) % n);
    }
    t = expMod02 (a, (p-1)/2, n);
    return ((a * ((t^2) % n)) % n);
}

vector <int> getBinary (int n)
{
    //while (n>1)
}


int expMod03 (int a, int k, int n)
{
    int b=1;
    int iA;

    if (k = 0) return b;
    iA = a;

}

int main()
{
    vector <int> viRespuesta;
    vector <int> viRespEras;
    int inumero, iA, iB, iC, iprimo;


    cout<<"Ingrese A:"<<endl;
    cin>>iA;
    cout<<"Ingrese B:"<<endl;
    cin>>iB;

    /*
    cout <<"Respuesta Algoritmo 1:"<<endl;
    cout << algorithm01(iA, iB) << endl;
    cout <<"Respuesta Algoritmo 2:"<<endl;
    cout << algorithm02(iA, iB) << endl;
    cout <<"Respuesta Algoritmo 3:"<<endl;
    cout << algorithm03(iA, iB) << endl;

    cout <<"Respuesta Algoritmo BinaryGCD (4):"<<endl;
    //cout<< algorithmBinaryGCD (219, 93) << endl;

    cout <<"Respuesta Algoritmo GCD (5):"<<endl;
    cout<< algorithmGCD(iA, iB) << endl;
    */

    cout <<"Respuesta Algoritmo Extendido (6):"<<endl;
    viRespuesta = extendidoEuclides(iA,iB);
    cout<< "G ="<< viRespuesta[0]<<endl;
    cout<< "U ="<< viRespuesta[1]<<endl;
    cout<< "V ="<< viRespuesta[2]<<endl;


    cout <<"Respuesta Algoritmo ExtendidoGCD (7):"<<endl;
    cout<<extendidoEuclidesGCD (iA, iB)<<endl;

    /*
    cout<<"Saber si es primo:"<<endl;
    cin>>iprimo;

    if (esPrimo(iprimo))
        {cout<<"Es Primo"<<endl;}
    else
        {cout<<"No es Primo"<<endl;}

    cout<<"Criba de Erastotenes: Ingrese numero"<<endl;
    cin>>inumero;
    viRespEras = cribaErastotenes(inumero);
    for (int i = 0; i < viRespEras.size(); i++)
    {
        cout<<viRespEras[i]<<endl;
    }*/

    /*
    cout<<"Inversa de Modulo N"<<endl;
    cout<<"Numero"<<endl;
    cin>>iA;
    cout<<"Modulo"<<endl;
    cin>>iB;
    cout<<"La inversa es:"<<endl;
    cout<<inversaMod (iA, iB);
    cout<<endl;

    cout<<"Exponenciacion Modular"<<endl;
    cout<<"Base:"<<endl;
    cin>>iA;
    cout<<"Exponente:"<<endl;
    cin>>iB;
    cout<<"Modulo:"<<endl;
    cin>>iC;
    cout<<"Exp. Modular: Algoritmo 01: Resultado es:"<<endl;
    cout<<expMod01(iA, iB, iC)<<endl;
    cout<<"Exp. Modular: Algoritmo 02: Resultado es:"<<endl;
    cout<<expMod02(iA, iB, iC)<<endl;
    return 0;
    */
}
