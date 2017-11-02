#pragma once
#include <iostream>
#include <fstream>
using namespace std;

ref class Lector
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
	//void ImprimirAlumProm15 (char * ccurso1, char * ccurso2);

};
