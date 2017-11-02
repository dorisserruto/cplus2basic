#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <string>

using namespace std;

class Alumno{
	private:
		int iCodigo;
        string sNombre;
        string sDirecc;
        string sTelefono;
		int iEdad;
		int iAIngreso;

	public:
		Alumno(int codigo, string nombre, string direccion, string telefono, int edad, int ingreso);

		~Alumno();

		//bool insAlumno(string nombre, string direccion, string telefono, int edad, int ingreso);
		bool updAlumno(int codigo, string nombre, string direccion, string telefono, int edad, int ingreso);
		bool delAlumno(int codigo);
		void prntAlumno();
};

#endif // ALUMNO_H_INCLUDED
