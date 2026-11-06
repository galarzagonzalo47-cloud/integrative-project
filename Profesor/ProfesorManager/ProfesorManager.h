#pragma once
#include "../ProfesorArchivo/ProfesorArchivo.h"

class ProfesorManager{
    private:
    ProfesorArchivo _archivoProfesor;
    bool ValidarProfesor(int numProfesor, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNacimiento, int posExcluir = -1);
    public:
    ProfesorManager();
    void cargarProfesor();
    void listarProfesor();
    void buscarProfesor();
    void modificarProfesor();
    void mostrarMenu();
};