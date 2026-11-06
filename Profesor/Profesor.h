#pragma once
#include <iostream>
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

    void setNumProfesor( int _NumProfesor);
    void setDni(int _Dni);
    void setNombre(std::string _nombre);
    void setApellido(std::string _apellido);
    void setTelefono(std::string _telefono);
    void setEmail(std::string _email);
    void setFechaNacimiento(Fecha _fechaNacimiento);
    void setEstado(bool _estado);
};