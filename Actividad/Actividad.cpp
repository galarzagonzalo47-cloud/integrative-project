#include "Actividad.h"

Actividad::Actividad(){
    _numActividad = 0;
    strcpy(_nombre, "");
    _numProfesor = 0;
    _numDisciplina = 0;
    _numSede = 0;
    _fechaInicio = Fecha();
    _arancel = 0.0;
    _cupoMaximo = 0;
    _estado = false;
}

int Actividad::getNumActividad(){
    return _numActividad;
}
std::string Actividad::getNombre(){
    return std::string(_nombre);
}
int Actividad::getNumProfesor(){
    return _numProfesor;
}
int Actividad::getNumDisciplina(){
    return _numDisciplina;
}
int Actividad::getNumSede(){
    return _numSede;
}
Fecha Actividad::getFechaInicio(){
    return _fechaInicio;
}
float Actividad::getArancel(){
    return _arancel;
}
int Actividad::getCupoMaximo(){
    return _cupoMaximo;
}
bool Actividad::getEstado(){
    return _estado;
}


void Actividad::setNumActividad(int numActividad){
    _numActividad = numActividad;
}
void Actividad::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}
void Actividad::setNumProfesor(int numProfesor){
    _numProfesor = numProfesor;
}
void Actividad::setNumDisciplina(int numDisciplina){
    _numDisciplina = numDisciplina;
}
void Actividad::setNumSede(int numSede){
    _numSede = numSede;
}
void Actividad::setFechaInicio(Fecha fechaInicio){
    _fechaInicio = fechaInicio;
}
void Actividad::setArancel(float arancel){
    _arancel = arancel;
}
void Actividad::setCupoMaximo(int cupoMaximo){
    _cupoMaximo = cupoMaximo;
}
void Actividad::setEstado(bool estado){
    _estado = estado;
}