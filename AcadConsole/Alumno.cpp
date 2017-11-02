#include <iostream>
#include "Alumno.h"

Alumno::Alumno(int codigo, string nombre, string direccion, string telefono, int edad, int ingreso){
    iCodigo = codigo;
    sNombre = nombre;
    sDirecc = direccion;
    sTelefono = telefono;
    iEdad = edad;
    iAIngreso = ingreso;
}

bool Alumno::updAlumno(int codigo, string nombre, string direccion, string telefono, int edad, int ingreso){
    sNombre = nombre;
    sDirecc = direccion;
    sTelefono = telefono;
    iEdad = edad;
    iAIngreso = ingreso;
}

void Alumno::prntAlumno(){
    cout<<"Codigo: "<<iCodigo<<endl;
    cout<<"Nombre: "<<sNombre<<endl;
    cout<<"Direccion: "<<sDirecc<<endl;
    cout<<"Telefono: "<<sTelefono<<endl;
    cout<<"Edad: "<<iEdad<<endl;
    cout<<"Año de Ingreso: "<<iAIngreso<<endl;
}
