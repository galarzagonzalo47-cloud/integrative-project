#include "Sedes.h"
#include <iostream>
#include <cstring>

Sedes::Sedes(){
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_direccion, "");
    strcpy(_telefono, "");
    _estado = false;
}

int Sedes::getId() const{
    return _id;
}

std::string Sedes::getNombre() const{
    return _nombre;
}

std::string Sedes::getDireccion() const{
    return _direccion;
}

std::string Sedes::getTelefono() const{
    return _telefono;
}

bool Sedes::getEstado() const{
    return _estado;
}

void Sedes::setId(int id){
    _id = id;
}

void Sedes::setNombre(std::string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}

void Sedes::setDireccion(std::string direccion){
    strncpy(_direccion, direccion.c_str(), sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
}

void Sedes::setTelefono(std::string telefono){
    strncpy(_telefono, telefono.c_str(), sizeof(_telefono) - 1);
    _telefono[sizeof(_telefono) - 1] = '\0';
}

void Sedes::setEstado(bool estado){
    _estado = estado;
}

void Sedes::mostrar() const{
    std::cout << "========================================" << std::endl;
    std::cout << "ID de la sede: " << _id << std::endl;
    std::cout << "Nombre de la sede: " << _nombre << std::endl;
    std::cout << "Direccion de la sede: " << _direccion << std::endl;
    std::cout << "Telefono de la sede: " << _telefono << std::endl;
    std::cout << "========================================" << std::endl;
}
