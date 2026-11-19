#include "Disciplina.h"
#include <cstring>

Disciplina::Disciplina(){
    _numDisciplina=0;
    strcpy(_nombre,"");
    strcpy(_descripcion,"");
    _estado=false;
}
int Disciplina::getNumDiscplina(){
    return _numDisciplina;
}
std::string Disciplina::getNombre(){
    return _nombre;
}
std::string Disciplina::getDescripcion(){
    return _descripcion;
}
bool Disciplina::getEstado(){
    return _estado;
}
void Disciplina::setNumDiscplina(int numDisciplina){
    _numDisciplina=numDisciplina;
}
void Disciplina::setNombre(std::string nombre){
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}
void Disciplina::setDescripcion(std::string descripcion){
    strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
}
void Disciplina::setEstado(bool estado){
    _estado=estado;
}
