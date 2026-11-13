#include <cstring>
#include "Inscripcion.h"

Inscripcion::Inscripcion() {
    _numInscripcion = 0;
    _numActividad = 0;
    _numSocio = 0;
    _fechaInscripcion = Fecha();
    _estado = false;
}

int Inscripcion::getNumInscripcion() {
    return _numInscripcion;
}

int Inscripcion::getNumActividad() {
    return _numActividad;
}

int Inscripcion::getNumSocio() {
    return _numSocio;
}

Fecha Inscripcion::getFechaInscripcion() {
    return _fechaInscripcion;
}

bool Inscripcion::getEstado() {
    return _estado;
}

void Inscripcion::setNumInscripcion(int numInscripcion) {
    _numInscripcion = numInscripcion;
}

void Inscripcion::setNumActividad(int numActividad) {
    _numActividad = numActividad;
}

void Inscripcion::setNumSocio(int numSocio) {
    _numSocio = numSocio;
}

void Inscripcion::setFechaInscripcion(Fecha fechaInscripcion) {
    _fechaInscripcion = fechaInscripcion;
}

void Inscripcion::setEstado(bool estado) {
    _estado = estado;
}

void Inscripcion::mostrar() {
    std::cout << "Numero de Inscripcion: " << _numInscripcion << std::endl;
    std::cout << "Numero de Actividad: " << _numActividad << std::endl;
    std::cout << "Numero de Socio: " << _numSocio << std::endl;
    std::cout << "Fecha de Inscripcion: ";
    _fechaInscripcion.mostrar();
    std::cout << std::endl;
    std::cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << std::endl;
}