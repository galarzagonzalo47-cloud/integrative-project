#pragma once
#include <iostream>
#include "Migrador.h"
#include "SociosArchivo.h"


class SociosManager{
    private:
    SociosArchivo _archivo;
    bool ValidarSocio(int numSocio, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNacimiento, int posExcluir = -1);
    public:
    SociosManager();
    void exportarACSV();
    void cargarSocios();
    void listarSocios();
    void buscarSocios();
    void modificarSocios();
};