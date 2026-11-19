#pragma once
#include <string>
#include "../Clubes.h"

class ClubesArchivo{
    private:
    std::string _nombreArchivo;

    public:
    ClubesArchivo();

    bool guardar(Clubes reg); //guardar al final del archivo
    Clubes leer(int pos); //lee el registro de la posicion pos del archivo y lo devuelve
    int getCantidadRegistros(); //devuelve la cantidad de registros del archivo
    int buscarPorID(int id); //busca un registro por numero de socio y devuelve la posicion del mismo, si no lo encuentra devuelve -1
    int buscarPorDni(int dni); //busca un registro por DNI y devuelve la posicion del mismo, si no lo encuentra devuelve -1
    bool modificar(Clubes reg, int pos); //sobrescribe el registro de la posicion pos del archivo con los datos de reg
};
