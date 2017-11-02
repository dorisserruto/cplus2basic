#include "string.h"
#include <cstdlib>
#include <iostream>

using namespace std;


String::String(char * cadena)
{
	this -> cadena = cadena;
}

String::String()
{
	cadena = 0;
}

bool String:: isNull()const
{/*
int cant=cadena.len();
if (cant==0)
{
return 1;
}
return 0;*/
}

int String::compare( const String  &otra)
{
  int TheSame = 1;
  int i = 0;
  String entro (otra);
  char *entrada=entro.c_str();
  while(cadena[i] && entrada[i])
  {
    if(cadena[i] != entrada[i])
    {
      TheSame = 0;
      break;
    }
    i++;
  }
  return (TheSame);
}



void String::erase()
{
  cadena = "";
}


/*
String::String(const String & cadena)
{
  char * nuevo;
	cout<<(*cadena).c_str()<<endl;
  nuevo = new char[cadena -> len()];
	int i = 0;
  for(i = 0; i < cadena.len(); i++)
	{
    nuevo[i] = cadena[i];
  }
  nuevo[i] = '\0';
  this -> cadena = nuevo;
}
*/

bool String::operator ==(String comparador)
{
  bool TheSame = true;
  int i = 0;
  char * entrada = comparador.c_str();
  while(cadena[i] && entrada[i])
  {
    if(cadena[i] != entrada[i])
    {
      TheSame = false;
      break;
    }
    i++;
  }
  return (TheSame);
}

bool String::operator ==(char * otro)
{
  String comparador(otro);
  bool TheSame = true;
  int i = 0;
  char * entrada = comparador.c_str();
  while(cadena[i] && entrada[i])
  {
    if(cadena[i] != entrada[i])
    {
      TheSame = false;
      break;
    }
    i++;
  }
  return (TheSame);
}

bool String::operator !=(String comparador)
{
  return !(*this == comparador);
}

bool String::operator !=(char * comparador)
{
  String nuevo(comparador);
  return !(*this == nuevo);
}

char * String::c_str()
{
  return cadena;
}

void String::operator +=(String aConcatenar)
{
  int i, j;
  i = j = 0;
  char * entrada = aConcatenar.c_str();

  int contador = 0;
  while(cadena[i])
  {
    i++;
  }
  while(entrada[j])
  {
    j++;
  }
  contador = i+j;

  char * nuevo = new char[contador];

  i = j = 0;
  while(cadena[i])
  {
    nuevo[i] = cadena[i];
    i++;
  }
  while(entrada[j])
  {
    nuevo[i] = entrada[j];
    j++;
    i++;
  }
  nuevo[i] = '\0';
  delete cadena;
  cadena = nuevo;
}


String String::operator +(String aConcatenar)
{
  int i, j;
  i = j = 0;
  char * entrada = aConcatenar.c_str();

  int contador = 0;
  while(cadena[i])
  {
    i++;
  }
  while(entrada[j])
  {
    j++;
  }
  contador = i+j;

  char * nuevo = new char[contador];

  i = j = 0;
  while(cadena[i])
  {
    nuevo[i] = cadena[i];
    i++;
  }
  while(entrada[j])
  {
    nuevo[i] = entrada[j];
    j++;
    i++;
  }
  nuevo[i] = '\0';

  String salida(nuevo);
  return salida;
}

String String::operator+(char * aConcatenar)
{
  int n = size(aConcatenar);
  int m = this -> len();
  int i = 0;
  char * salida = new char [m+n+1];

  for(i=0; i<m; i++)
    salida[i] = cadena[i];
  for(i=0; i<n; i++)
    salida[m+i] = aConcatenar[i];
  salida[m+n]='\0';
  String nuevo(salida);
  return nuevo;
}

int String::len()
{
  int i;
  i = 0;

  while(cadena[i])
  {
    i++;
  }
  return i;
}

int String::size(char * caracteres)
{
  int i;
  i = 0;

  while(caracteres[i])
  {
    i++;
  }
  return i;
}


bool String::operator <(String comparador)
{
  int interno = this -> len();
  int externo = comparador.len();
  return (interno < externo);
}

bool String::operator <(char * comparador)
{
  int interno = this -> len();
  int externo = size(comparador);
  return (interno < externo);
}

bool String::operator >(String comparador)
{
  int interno = this -> len();
  int externo = comparador.len();
  return (interno > externo);
}

String & String::operator =(String aAsignar)
{
  char * nuevo = new char[aAsignar.len()];

  int i;
  i = 0;
  char * entrada = aAsignar.c_str();
  while(entrada[i])
  {
    nuevo[i] = entrada[i];
    i++;
  }
  nuevo[i] = '\0';
  delete cadena;
  cadena = 0;
  cadena = nuevo;
  return * this;
}

String & String::operator =(char * aAsignar)
{
  int i;
  i = size(aAsignar);
  char * nuevo = new char [i+1];
  i = 0;

  while(aAsignar[i])
  {
    nuevo[i] = aAsignar[i];
    i++;
  }
  nuevo[i] = '\0';
  delete cadena;
  cadena = 0;
  cadena = nuevo;
  return * this;
}


ostream & operator<<(ostream & os, const String & Imprime)
{
  os << Imprime.cadena ;
  return os;
}

istream & operator>>(istream & is, const String & Entrada)
{
  is >> Entrada.cadena;
  return is;
}

char String::operator[](const int x)
{
  if (x >= 0)
  {
    return cadena[x];
  }
  else
    return ' ';
}

int String::find_first(char caracter)
{
  int i = 0;
  while(cadena[i])
  {
    if(cadena[i] == caracter) //  la pocicion - Desde 1
    {
      return i+1;
      break;
    }
    if (this -> len() == i+1) // Si no esta devuelve '0' cero
    {
      return 0;
      break;
    }
    i++;
  }
}

int String::find_last(char caracter)
{
  int i = 0;
  int temp = 0;
  while(cadena[i])
  {
    if(cadena[i] == caracter) //  pocicion - Desde 1
    {
      temp = i;
    }
    i++;
  }
  return temp+1;
}


void String::setCadena(char * newCadena)
{
  cadena = newCadena;
}

String::~String()
{
	delete cadena;
}
