#pragma once
#include "../SedesArchivo/SedesArchivo.h"

class SedesManager{
    private:
    SedesArchivo _archivo;
    int pedirOpcion();

    public:
    void mostrarMenu();
    void cargarSedes();
    void listarSedes();
    void buscarSedes();
    void modificarSedes();
    void buscarSedePorID();
    void buscarSedePorNombre();
};