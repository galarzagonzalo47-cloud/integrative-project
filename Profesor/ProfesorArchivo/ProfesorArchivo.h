#pragma once
#include "../Profesor.h"

class ProfesorArchivo{
    private:
    std::string _nombreDeArchivo;

    public:
    ProfesorArchivo();

    bool guardar (Profesor pos);
    Profesor leer (int pos);
    int getCantidadDeRegistro();
    int buscarPorId (int pos);
    int buscarPorDni (int dni);
    int modificarPorId (Profesor reg, int pos);
};