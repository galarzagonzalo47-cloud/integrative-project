#pragma once
#include <iostream>
#include "Socios.h"

class SociosArchivo{
    private:
    std::string _nombreArhivo;

    public:
    SociosArchivo();

    bool guardar(Socios reg); //guardar al final del archivo
    Socios leer(Socios &reg, int pos); //lee el registro de la posicion pos del archivo y lo guarda en reg
    int getCantidadRegistros(); //devuelve la cantidad de registros del archivo
    int buscarPorID(int id); //busca un registro por ID y devuelve la posicion del mismo, si no lo encuentra devuelve -1
    int modificar(Socios reg, int pos); //modifica el registro de la posicion pos del archivo con los datos de reg
    


};


/*
listar todos
leer x pos
cantidad
guardar
modificar
buscar
*/