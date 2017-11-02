#include "Lector.h"

Lector::Lector(void)
{
}
//Inicializa la lista de los alumnos segun el nombre del archivo indicado
Lector::Lector(char * alumnos){
	ListaAlumnos = alumnos;
};

// Imprime nombre de los alumnos por curso
void Lector::ImprimNombresXCurso (char * ccurso){
	ifstream fcurso (ccurso);
	char ccodigo[10];
	char * cnombre = new char[100];
	char cbuffer[1000];

	while (!fcurso.eof()) {
		fcurso>>ccodigo;
		cnombre = BuscarNombre (ccodigo);
		if (cnombre != 0){
			cout<<cnombre<<endl;
		}
		else{
			cout<<"Ocurrio un error. Alumno no encontrado"<<endl;
		}
		fcurso.getline(cbuffer,1000);
	}
}

//Busca el nombre del alumno por codigo en la lista de alumnos indicada
char * Lector::BuscarNombre (char ccodigo[10]){
	ifstream flistado (ListaAlumnos);
	char ccodigo_alumno[10];
	char * cnombre_alumno = new char[100];
	char cbuffer[1000];

	while (!flistado.eof()){
		flistado.getline(ccodigo_alumno,11,'#');
		if (strcmp(ccodigo_alumno,ccodigo) == 0){ //si ambos códigos son iguales
			flistado.getline(cnombre_alumno,100,'#'); //obtener el nombre del alumno
			return cnombre_alumno;
		}
		flistado.getline(cbuffer,1000);
	}
	return 0; //No encontró el nombre
}

// Imprime nombre de los alumnos varones por curso
void Lector::ImprimVaronesXCurso (char * ccurso){
	ifstream fcurso (ccurso);
	char ccodigo[10];
	char * cnombre;
	char cbuffer[1000];

	while (!fcurso.eof()) {
		fcurso>>ccodigo;
		if (EsHombre(ccodigo)){
			cnombre = BuscarNombre(ccodigo);
			if (cnombre != 0){
				cout<<cnombre<<endl;
			}
			else{
				cout<<"Ocurrio un error. Alumno no encontrado"<<endl;
			}
		}
		fcurso.getline(cbuffer,1000);
	}
}

//Indica si es Hombre el alumno con el codigo recibido
bool Lector::EsHombre(char ccodigo[10]){
	ifstream flistado (ListaAlumnos);
	char csexo;
	char ccodigo_alumno[10];
	char cbuffer[100];

	while (!flistado.eof()){
		flistado.getline(ccodigo_alumno,11,'#'); //obtiene el codigo
		flistado.getline(cbuffer,100,'#'); //saca en el buffer el nombre (no sera utilizado)
		flistado>>csexo; //obtiene el sexo

		if (strcmp(ccodigo_alumno,ccodigo) == 0){
			if (csexo == 'M'){return true;}
			else{return false;}
		}
		flistado.getline(cbuffer,100);
	}
	return 0; //No al alumno(a)
}

void Lector::ImprimirPromedioTotalMujeres (char * ccurso){
	ifstream fcurso (ccurso);
	ifstream flistado (ListaAlumnos);
	char ccodigo[10];
	char * cnombre;

	float flalumnos=0.0;
	float flprom_alumno=0.0;
	float fltotal_alumnos=0.0;

	char cbuffer[1000];

	while (!fcurso.eof()) {
		fcurso>>ccodigo;

		if (!EsHombre(ccodigo)){
			//imprimir nombre de la alumna
			cnombre = BuscarNombre(ccodigo);
			if (cnombre != 0){
				cout<<cnombre<<' ';

				//imprimir promedio de la alumna
				flprom_alumno = calcularPromedio(ccurso,ccodigo);
				cout<<" - Promedio:"<<flprom_alumno<<endl;
				fltotal_alumnos = fltotal_alumnos + flprom_alumno;
				flalumnos++;

			}
			else{cout<<"Ocurrio un error. Alumno no encontrado"<<endl;}
		}
		fcurso.getline(cbuffer,1000);
	}
	cout<<"Promedio total:"<<(fltotal_alumnos/flalumnos)<<endl;
}

//Calcula el promedio
float Lector::calcularPromedio(char * ccurso, char ccodigo[10]){
	ifstream fcurso (ccurso);
	float flnota1;
	float flnota2;
	float flnota3;
	float flpromedio;

	char cbuffernota[4];

	char ccodigo_alumno[10];
	char cbuffer[100];

	while (!fcurso.eof()){
		fcurso.getline(ccodigo_alumno,11,' '); //obtiene el codigo

		if (strcmp(ccodigo_alumno,ccodigo) == 0){
			fcurso.getline(cbuffernota,4,' '); //saca la primera nota
			flnota1 = atof(cbuffernota);
			fcurso.getline(cbuffernota,4,' '); //saca la segunda nota
			flnota2 = atof(cbuffernota);
			fcurso.getline(cbuffernota,4,' '); //saca la tercera nota
			flnota3 = atof(cbuffernota);

			flpromedio = (flnota1 + flnota2 + flnota3)/3;

			return flpromedio;
		}
		fcurso.getline(cbuffer,100);
	}
	return (-1.0); //No al alumno(a)
}

//Imprime el nombre y promedio de los alumnos jalados en el curso indicado
void Lector::ImprimirAlumnosJalados (char * ccurso){
	ifstream fcurso (ccurso);
	char ccodigo[10];
	char * cnombre;

	float flprom_alumno=0.0;

	char cbuffer[1000];

	while (!fcurso.eof()) {
		fcurso>>ccodigo;
		flprom_alumno = calcularPromedio(ccurso,ccodigo);

		if (flprom_alumno < (11.1)){
			cnombre = BuscarNombre(ccodigo);
			if (cnombre != 0){
				cout<<cnombre;
				cout<<" - Promedio:"<<flprom_alumno<<endl;
			}
			else{cout<<"Ocurrio un error. Alumno no encontrado"<<endl;}
		}
		fcurso.getline(cbuffer,1000);
	}
}

void Lector::ImprimirAlumnosProm15 (char * ccurso1, char * ccurso2){
	ifstream fcurso1 (ccurso1);
	ifstream fcurso2 (ccurso2);

	char ccodigo[10];
	char * cnombre;

	float flprom1_alumno=0.0;
	float flprom2_alumno=0.0;

	char cbuffer[1000];

	while (!fcurso1.eof()) {
		fcurso1>>ccodigo;
		flprom1_alumno = calcularPromedio(ccurso1,ccodigo);
        flprom2_alumno = calcularPromedio(ccurso2,ccodigo);

		if (flprom1_alumno > (15.0) && flprom2_alumno > (15.0)){
            cnombre = BuscarNombre(ccodigo);
            if (cnombre != 0){
                cout<<cnombre;
                cout<<" - Promedio 1:"<<flprom1_alumno;
                cout<<" - Promedio 2:"<<flprom2_alumno<<endl;
            }
            else{cout<<"Ocurrio un error. Alumno no encontrado"<<endl;}
		}
		fcurso1.getline(cbuffer,1000);
	}
}



