#pragma once
#include "../Disciplina.h"

class DisciplinaArchivo{
    private:
    std::string _nombreArchivo;

    public:
    DisciplinaArchivo();
    bool guardar(Disciplina disciplina);
    Disciplina leer(int pos);
    bool modificar(Disciplina disciplina, int pos);
    int getCantidadRegistros();
    int buscarPorId(int id);
}