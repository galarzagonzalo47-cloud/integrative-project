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
    return _fechaNacimineto;
}
bool Profesor::getEstado(){
    return _estado;
}

void Profesor::setNumProfesor(int NumProfesor){
    _numProfesor=NumProfesor;
}
void Profesor::setDni(int dni){
    _dni=dni;
}
void Profesor::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}
void Profesor::setApellido(std::string apellido){
    strcpy(_apellido, apellido.c_str());
}
void Profesor::setTelefono(std::strinng telefono){
    strcpy(_telefono, telefono.c_str());
}
void Profesor::setEmail(std::string email){
    strcpy(_email, email.c_str());
}
void Profesor::setFechaNacimiento(Fecha fechanacimiento){
    _fechaNacimineto=fechanacimiento;
}
void Profesor::setEstado(bool estado){
    _estado=estado;
}