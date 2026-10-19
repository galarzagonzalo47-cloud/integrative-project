#include "Socios.h"

Socios::Socios(){
    _numSocio = 0 ;
    _dni = 0 ;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _estado=false;
};

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

void Socios::setNumSocio(int _NumSocio){
    _numSocio = _NumSocio;
}
void Socios::setDni(int _Dni){
    _dni = _Dni;
}
void Socios::setNombre(std::string _Nombre){
    strcpy(_nombre, _Nombre.c_str());
}
void Socios::setApellido(std::string _Apellido){
    strcpy(_apellido, _Apellido.c_str());
}
void Socios::setTelefono(std::string _Telefono){
    strcpy(_telefono, _Telefono.c_str());
}
void Socios::setEmail(std::string _Email){
    strcpy(_email, _Email.c_str());
}
void Socios::setEstado(bool _Estado){
    _estado = _Estado;
}