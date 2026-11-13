#pragma once
#include <string>
#include "../ActividadArchivo/ActividadArchivo.h"

class ActividadManager{
    private:
    ActividadArchivo _archivoActividad;

    public:
    ActividadManager();
    void cargarActividad();
    void listarActividad();
    void buscarActividad();
    void modificarActividad();
    void darDeBajaActividad();
    void mostrarMenu();
};