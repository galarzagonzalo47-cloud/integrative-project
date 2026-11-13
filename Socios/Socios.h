#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "../Fecha/Fecha.h"

using namespace std;

class Socios{ //Clase Socios
    private:
    int _numSocio;
    int _dni;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email [40];
    Fecha _fechaNacimiento;
    bool _estado;

    public:
    Socios();

    int getNumSocio();
    int getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getEmail();
    Fecha getFechaNacimiento();
    bool getEstado();

    void setNumSocio(int numSocio);
    void setDni(int dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setFechaNacimiento(Fecha fechaNacimiento);
    void setEstado(bool estado);

    void mostrar();
};

/*
Socio.dat
NumSocio : int
Dni : int
Nombre : char[30]
Apellido : char[30]
Telefono : char[20]
Email : char[40]
FechaNacimiento : Fecha
Estado : bool
*/
