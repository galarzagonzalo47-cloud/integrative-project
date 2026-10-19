#pragma once
#include <iostream>
#include "Migrador.h"
#include "SociosArchivo.h"


class SociosManager{
    private:
    SociosArchivo _archivo;
    public:
    SociosManager();
    void exportarACSV();
    void cargarSocios();
    void listarSocios();
    void buscarSocios();
    void modificarSocios();
};