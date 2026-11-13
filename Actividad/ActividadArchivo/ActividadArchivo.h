#pragma once
#include "Actividad.h"

class ActividadArchivo{
    private:
    std::string _nombreArchivo;

    public:
    ActividadArchivo();
    bool guardar(Actividad reg);
    Actividad leer(int pos);
    bool modificar(Actividad reg, int pos);
    int getCantidadRegistros();
    int buscarPorId(int id);
};