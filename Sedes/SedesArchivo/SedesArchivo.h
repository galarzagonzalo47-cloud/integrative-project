#pragma once
#include <string>
#include "../Sedes.h"

class SedesArchivo{
    private:
    std::string _nombreArchivo;

    public:
    SedesArchivo();

    bool guardar(Sedes reg); //guarda el registro al final del archivo
    Sedes leer(int pos); //devuelve el registro de la posicion pos del archivo
    int getCantidadRegistros(); //devuelve la cantidad de registros del archivo
    int buscarPorID(int id); //busca un registro por ID y devuelve su posicion, si no lo encuentra devuelve -1
    int buscarPorNombre(std::string nombre); //busca un registro por nombre y devuelve su posicion, si no lo encuentra devuelve -1
    bool modificar(Sedes reg, int pos); //sobrescribe el registro de la posicion pos con los datos de reg
};