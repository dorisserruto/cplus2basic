#ifndef STRING_H
#define STRING_H
#include "string.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class String
{
	private:
		char * cadena;
	public:

 		String(char * cadena);
		String();

	    int compare(const String & otraCadena);
	    int len();
		int size(char * caracteres);
		char * c_str();
	    int find_first(char caracter);
		int find_last(char caracter);
		void setCadena(char * newCadena);
		~String();
		bool isNull()const;

        void erase();
        bool operator ==(String comparador);
        bool operator ==(char * otro);
		bool operator !=(String comparador);
		bool operator !=(char * comparador);
		void operator +=(String aConcatenar);
		String operator +(String aConcatenar);
		String operator +(char * aConcatenar);
		bool operator <(String comparador);
		bool operator <(char * comparador);
		bool operator >(String comparador);
		String & operator =(String aAsignar);
		String & operator =(char * aAsignar);
		friend ostream & operator << (ostream & os, const String & Imprime);
        friend istream & operator >> (istream & is, const String & Entrada);
		char operator[](const int x);

};

#endif
