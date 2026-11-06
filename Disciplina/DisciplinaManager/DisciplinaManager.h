#pragma once
#include "../Disciplina.h/DisciplinaArchivo.h"

class DisciplinaManager{
    private:
    DisciplinaArchivo _archivo;

    public:
    DisciplinaManager();
    void cargarDisciplina();
    void listarDisciplina();
    void buscarDisciplina();
    void modificarDisciplina();
    void mostrarMenu();
};