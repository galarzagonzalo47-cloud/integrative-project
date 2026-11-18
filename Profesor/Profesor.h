#pragma once
#include <iostream>
#include <string>
#include "../Fecha/Fecha.h"

class Profesor{
    private:
    int _numProfesor;
    int _dni;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email [40];
    Fecha _fechaNacimiento;
    bool _estado;

    public:
    Profesor();

    int getNumProfesor();
    int getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getEmail();
    Fecha getFechaNacimiento();
    bool getEstado();

    void setNumProfesor(int numProfesor);
    void setDni(int dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setFechaNacimiento(Fecha fechaNacimiento);
    void setEstado(bool estado);

    void mostrar();
};
