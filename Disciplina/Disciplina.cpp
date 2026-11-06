#include "Disciplina.h"

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
    strcpy(_nombre, nombre.c_str());
}
void Disciplina::setDescripcion(std::string descripcion){
    strcpy(_descripcion, descripcion.c_str());
}
void Disciplina::setEstado(bool estado){
    _estado=estado;
}


