#pragma once
#include <string>

class Sedes{
    private:
    int _id;
    char _nombre[40];
    char _direccion[60];
    char _telefono[20];
    bool _estado;

    public:
    Sedes();

    int getId() const;
    std::string getNombre() const;
    std::string getDireccion() const;
    std::string getTelefono() const;
    bool getEstado() const;

    void setId(int id);
    void setNombre(std::string nombre);
    void setDireccion(std::string direccion);
    void setTelefono(std::string telefono);
    void setEstado(bool estado);

    void mostrar() const;
};
