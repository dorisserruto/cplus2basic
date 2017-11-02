#include "lector.h"

lector::lector()
{
}

lector::~lector()
{
}

string lector::leerArchivo ( char * cfile )
{
    string stexto;
    char * cbuffer = new char[1000];
    ifstream farchivo(cfile);

    while (!farchivo.eof()){
        farchivo.getline(cbuffer,1000);
        //farchivo>>cbuffer;
        stexto = stexto +""+ string(cbuffer);
        //stexto = string(cbuffer);
    }
     return stexto;
}

void lector::escribirArchivo ( char * cfile, string scontenido )
{
    ofstream farchivo(cfile);
    farchivo << scontenido <<endl;
    farchivo.close();
}

