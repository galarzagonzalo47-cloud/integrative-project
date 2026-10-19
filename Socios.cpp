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