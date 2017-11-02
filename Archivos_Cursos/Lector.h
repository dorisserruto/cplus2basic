#ifndef LECTOR_H_INCLUDED
#define LECTOR_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

class Lector
{
public:
	char * ListaAlumnos;

	Lector(void);
	Lector(char * alumnos);
	void ImprimNombresXCurso (char * ccurso);
	char* BuscarNombre (char ccodigo[10]);
	void ImprimVaronesXCurso (char * ccurso);
	bool EsHombre(char ccodigo[10]);
	void ImprimirPromedioTotalMujeres (char * ccurso);
	float calcularPromedio(char * ccurso, char ccodigo[10]);
	void ImprimirAlumnosJalados (char * ccurso);
	void ImprimirAlumnosProm15 (char * ccurso1, char * ccurso2);

};

#endif // LECTOR_H_INCLUDED
