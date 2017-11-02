#ifndef LECTOR_H_INCLUDED
#define LECTOR_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

class lector
{
public:
    lector();
	virtual ~lector();

	string leerArchivo ( char * cfile );
	void escribirArchivo ( char * cfile, string scontenido );

};

#endif // LECTOR_H_INCLUDED
