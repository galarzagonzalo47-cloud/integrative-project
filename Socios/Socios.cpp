#include "Socios.h"
#include <cstring>

Socios::Socios(){
    _numSocio = 0;
    _dni = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _estado = false;
}

Fecha Socios::getFechaNacimiento(){
    return _fechaNacimiento;
}
int Socios::getNumSocio(){
    return _numSocio;
}
int Socios::getDni(){
    return _dni;
}
std::string Socios::getNombre(){
    return _nombre;
}
std::string Socios::getApellido(){
    return _apellido;
}
std::string Socios::getTelefono(){
    return _telefono;
}
std::string Socios::getEmail(){
    return _email;
}
bool Socios::getEstado(){
    return _estado;
}

void Socios::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}
void Socios::setNumSocio(int numSocio){
    _numSocio = numSocio;
}
void Socios::setDni(int dni){
    _dni = dni;
}
void Socios::setNombre(std::string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}
void Socios::setApellido(std::string apellido){
    strncpy(_apellido, apellido.c_str(), sizeof(_apellido) - 1);
    _apellido[sizeof(_apellido) - 1] = '\0';
}
void Socios::setTelefono(std::string telefono){
    strncpy(_telefono, telefono.c_str(), sizeof(_telefono) - 1);
    _telefono[sizeof(_telefono) - 1] = '\0';
}
void Socios::setEmail(std::string email){
    strncpy(_email, email.c_str(), sizeof(_email) - 1);
    _email[sizeof(_email) - 1] = '\0';
}
void Socios::setEstado(bool estado){
    _estado = estado;
}

void Socios::mostrar(){
    cout<<"========================================"<<endl;
    cout<<"Numero de socio: "<<_numSocio<<endl;
    cout<<"DNI del socio: "<<_dni<<endl;
    cout<<"Nombre del socio: "<<_nombre<<endl;
    cout<<"Apellido del socio: "<<_apellido<<endl;
    cout<<"Telefono del socio: "<<_telefono<<endl;
    cout<<"Email del socio: "<<_email<<endl;
    cout<<"Fecha de nacimiento del socio: ";
    _fechaNacimiento.mostrar();
    cout<<endl;
    cout<<"========================================"<<endl;
}
