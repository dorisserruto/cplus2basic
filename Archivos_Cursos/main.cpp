#include <iostream>
#include "lector.h"

/*
Instrucciones:
1.1. Imprimir los nombres de las personas que llevan el curso de OAD
1.2. Imprimir los nombres de las personas que llevan el curso de EDIII
2. Imprimir el nombre de todos los varones que estudian ED
3. Imprimir el promedio de todas las notas de todas las mujeres que estudian ED
4. Imprimir el nombre de todos los jalados en ED
5. Imprimir el nombre de las personas que han sacado la nota promedio mayor a 15 en ambos cursos (a la vez)
*/

using namespace std;

int main()
{
    Lector consulta1("listado.txt");

	//Instruccion 1.1
	cout<<"ALUMNOS DEL CURSO OAD"<<endl;
	cout<<endl;
	consulta1.ImprimNombresXCurso("oad.txt");

	cout<<endl;

	//Instruccion 1.2
	cout<<"ALUMNOS DEL CURSO EDIII"<<endl;
	cout<<endl;
	consulta1.ImprimNombresXCurso("eds.txt");

	cout<<endl;

	//Instruccion 2
	cout<<"ALUMNOS VARONES DEL CURSO EDIII"<<endl;
	cout<<endl;
	consulta1.ImprimVaronesXCurso("eds.txt");

	cout<<endl;

	//Instruccion 3
	cout<<"PROMEDIO DE NOTAS MUJERES EDIII"<<endl;
	cout<<endl;
	consulta1.ImprimirPromedioTotalMujeres("eds.txt");

	cout<<endl;

	//Instruccion 4
	cout<<"ALUMNOS JALADOS EN EDIII"<<endl;
	cout<<endl;
	consulta1.ImprimirAlumnosJalados("eds.txt");

	cout<<endl;

	//Instruccion 5
	cout<<"ALUMNOS CON PROMEDIO MAYOR A 15"<<endl;
	cout<<endl;
	consulta1.ImprimirAlumnosProm15("eds.txt","oad.txt");

	cout<<endl;


    return 0;
}
