#pragma once
#include <string>
#include "../Profesor.h"

class ProfesorArchivo{
    private:
    std::string _nombreDeArchivo;

    public:
    ProfesorArchivo();

    bool guardar(Profesor reg);
    Profesor leer(int pos);
    int getCantidadDeRegistro();
    int buscarPorId(int id);
    int buscarPorDni(int dni);
    bool modificar(Profesor reg, int pos);
};
