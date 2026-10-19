#pragma once
#include <iostream>
#include "SociosArchivo.h"


class SociosManager{
    private:
    SociosArchivo _archivo;
    public:
    SociosManager();
    void cargarSocios();
    void listarSocios();
    void buscarSocios();
    void modificarSocios();
};