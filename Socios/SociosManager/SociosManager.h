#pragma once
#include <string>
#include "../SociosArchivo/SociosArchivo.h"

class SociosManager{
    private:
    SociosArchivo _archivo;
    bool ValidarSocio(int numSocio, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNacimiento, int posExcluir = -1);

    public:
    SociosManager();
    void cargarSocios();
    void listarSocios();
    void buscarSocios();
    void modificarSocios();
    void darDeBajaSocio();
    void mostrarMenu();
    void buscarSocioPorID();
    void buscarSocioPorDni();
};
