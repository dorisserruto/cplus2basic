#include "ccaesar.h"
#include "cvigenere.h"
#include "cvernam.h"
#include "lector.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	lector iodatos;
	int iopcion;

	char * cnombre_archivo_fuente = new char [100];
	char * cnombre_archivo_destino = new char [100];

    cout<<"CIFRADO DE TEXTOS DESDE ARCHIVO Y FUNCIONES ADICIONALES"<<endl;
    cout<<"1. Cifrar texto segun Cifrado de CESAR"<<endl;
    cout<<"2. Descifrar texto segun Cifrado de CESAR"<<endl;
    cout<<"3. Cifrar texto segun Cifrado de VIGENERE"<<endl;
    cout<<"4. Descifrar texto segun Cifrado de VIGENERE"<<endl;
    cout<<"5. Cifrar texto segun Cifrado de VERNAM"<<endl;
    cout<<"6. Descifrar texto segun Cifrado de VERNAM"<<endl;

    cout<<endl;
    cout<<"Ingrese el numero de la accion deseada:"<<endl;
    cin>>iopcion;

    switch (iopcion) {
        case 1: {
            int iclave_ingresada;
            string stexto_a_cifrar;
            string stexto_cifrado;

            cout<<"CIFRADO DE CESAR"<<endl;
            cout<<"Ingrese clave de cesar"<<endl;
            cin>>iclave_ingresada;
            cout<<endl;

            ccaesar consulta_cesar_cif(iclave_ingresada);

            cout<<"Ingrese nombre de archivo fuente (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_fuente;
            cout<<endl;

            stexto_a_cifrar = iodatos.leerArchivo(cnombre_archivo_fuente);
            cout<<stexto_a_cifrar<<endl;


            stexto_cifrado = consulta_cesar_cif.cifrar(stexto_a_cifrar);

            cout<<"Ingrese nombre de archivo destino (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_destino;
            cout<<endl;
            iodatos.escribirArchivo (cnombre_archivo_destino,stexto_cifrado);

            break;
        }

        case 2: {
            int iclave_ingresada;
            string stexto_a_descifrar;
            string stexto_descifrado;

            cout<<"DESCIFRADO DE CESAR"<<endl;
            cout<<"Ingrese nombre de archivo fuente (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_fuente;
            cout<<endl;

            cout<<"Ingrese clave de cesar para descifrar el texto"<<endl;
            cin>>iclave_ingresada;
            cout<<endl;

            ccaesar consulta_cesar_desc(iclave_ingresada);

            stexto_a_descifrar = iodatos.leerArchivo(cnombre_archivo_fuente);
            cout<<stexto_a_descifrar<<endl;


            stexto_descifrado = consulta_cesar_desc.descifrar(stexto_a_descifrar);

            cout<<"Ingrese nombre de archivo destino (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_destino;
            cout<<endl;
            iodatos.escribirArchivo (cnombre_archivo_destino,stexto_descifrado);

            break;

        }

        case 3: {
            string sclave_ingresada;
            string stexto_a_cifrar;
            string stexto_cifrado;

            cout<<"CIFRADO DE VIGENERE"<<endl;
            cout<<"Ingrese clave de Vigenere"<<endl;
            cin>>sclave_ingresada;
            cout<<endl;

            cvigenere consulta_vigenere_cif(sclave_ingresada);


            cout<<"Ingrese nombre de archivo fuente (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_fuente;
            cout<<endl;

            stexto_a_cifrar = iodatos.leerArchivo(cnombre_archivo_fuente);
            cout<<stexto_a_cifrar<<endl;

            stexto_cifrado = consulta_vigenere_cif.cifrar(stexto_a_cifrar);

            cout<<"Ingrese nombre de archivo destino (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_destino;
            cout<<endl;
            iodatos.escribirArchivo (cnombre_archivo_destino,stexto_cifrado);

            break;
        }

        case 4: {
            string sclave_ingresada;
            string stexto_a_descifrar;
            string stexto_descifrado;

            cout<<"DESCIFRADO DE VIGENERE"<<endl;
            cout<<"Ingrese nombre de archivo fuente (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_fuente;
            cout<<endl;

            cout<<"Ingrese clave de vigenere para descifrar el texto"<<endl;
            cin>>sclave_ingresada;
            cout<<endl;

            cvigenere consulta_vigenere_desc(sclave_ingresada);

            stexto_a_descifrar = iodatos.leerArchivo(cnombre_archivo_fuente);
            cout<<stexto_a_descifrar<<endl;


            stexto_descifrado = consulta_vigenere_desc.descifrar(stexto_a_descifrar);

            cout<<"Ingrese nombre de archivo destino (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_destino;
            cout<<endl;
            iodatos.escribirArchivo (cnombre_archivo_destino,stexto_descifrado);

            break;
        }

       case 5: {
            string sclave_ingresada;
            string stexto_a_cifrar;
            string stexto_cifrado;

            cout<<"CIFRADO DE VERNAM"<<endl;
            cout<<"Ingrese nombre de archivo fuente (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_fuente;
            cout<<endl;

            cvernam consulta_vernam_cif;

            stexto_a_cifrar = iodatos.leerArchivo(cnombre_archivo_fuente);
            cout<<stexto_a_cifrar<<endl;

            stexto_cifrado = consulta_vernam_cif.cifrar(stexto_a_cifrar);

            cout<<"Ingrese nombre de archivo destino (incluyendo .txt)"<<endl;
            cin>>cnombre_archivo_destino;
            cout<<endl;
            iodatos.escribirArchivo (cnombre_archivo_destino,stexto_cifrado);

            break;
            /*
            cvernam x;
            //cout<<x.aBinario7(30)<<endl;
            //cout<<x.aDecimal7("0011110")<<endl;
            //cout<<x.XOR7("0011110","1101110")<<endl;
            //cout<<x.generarClave(20);*/
        }
    }

    return 0;
}
