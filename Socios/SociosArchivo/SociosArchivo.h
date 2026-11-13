#pragma once
#include <string>
#include "../Socios.h"

class SociosArchivo{
    private:
    std::string _nombreArchivo;

    public:
    SociosArchivo();

    bool guardar(Socios reg); //guardar al final del archivo
    Socios leer(int pos); //lee el registro de la posicion pos del archivo y lo devuelve
    int getCantidadRegistros(); //devuelve la cantidad de registros del archivo
    int buscarPorID(int id); //busca un registro por numero de socio y devuelve la posicion del mismo, si no lo encuentra devuelve -1
    int buscarPorDni(int dni); //busca un registro por DNI y devuelve la posicion del mismo, si no lo encuentra devuelve -1
    bool modificar(Socios reg, int pos); //sobrescribe el registro de la posicion pos del archivo con los datos de reg
};
