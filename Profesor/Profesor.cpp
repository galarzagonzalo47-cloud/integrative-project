#include <cstring>
#include "Profesor.h"

Profesor::Profesor(){
    _numProfesor=0;
    _dni=0;
    strcpy(_nombre,"");
    strcpy(_apellido,"");
    strcpy(_telefono,"");
    strcpy(_email,"");
    _estado=false;
}
int Profesor::getNumProfesor(){
    return _numProfesor;
}
int Profesor::getDni(){
    return _dni;
}
std::string Profesor::getNombre(){
    return _nombre;
}
std::string Profesor::getApellido(){
    return _apellido;
}
std::string Profesor::getTelefono(){
    return _telefono;
}
std::string Profesor::getEmail(){
    return _email;
}
Fecha Profesor::getFechaNacimiento(){
    return _fechaNacimiento;
}
bool Profesor::getEstado(){
    return _estado;
}

void Profesor::setNumProfesor(int numProfesor){
    _numProfesor=numProfesor;
}
void Profesor::setDni(int dni){
    _dni=dni;
}
void Profesor::setNombre(std::string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}
void Profesor::setApellido(std::string apellido){
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[sizeof(_apellido) - 1] = '\0';
}
void Profesor::setTelefono(std::string telefono){
    strncpy(_telefono, telefono.c_str(), sizeof(_telefono) - 1);
    _telefono[sizeof(_telefono) - 1] = '\0';
}
void Profesor::setEmail(std::string email){
    strncpy(_email, email.c_str(), sizeof(_email) - 1);
    _email[sizeof(_email) - 1] = '\0';
}
void Profesor::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento=fechaNacimiento;
}
void Profesor::setEstado(bool estado){
    _estado=estado;
}

void Profesor::mostrar(){
    std::cout<<"Numero de profesor: "<<_numProfesor<<std::endl;
    std::cout<<"DNI: "<<_dni<<std::endl;
    std::cout<<"Nombre: "<<_nombre<<std::endl;
    std::cout<<"Apellido: "<<_apellido<<std::endl;
    std::cout<<"Telefono: "<<_telefono<<std::endl;
    std::cout<<"Email: "<<_email<<std::endl;
    std::cout<<"Fecha de nacimiento: ";
    _fechaNacimiento.mostrar();
    std::cout<<std::endl;
}
