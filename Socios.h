#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Fecha.h"

using namespace std;


class Socios{ //Clase Socios
    private:
    int _numSocio;
    int _dni;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email [40];
    bool _estado;

    public:
    Socios();

    int getNumSocio();
    int getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getEmail();
    bool getEstado();

    void setNumSocio( int _NumSocio);
    void setDni(int _Dni);
    void setNombre(std::string _Nombre);
    void setApellido(std::string _Apellido);
    void setTelefono(std::string _Telefono);
    void setEmail(std::string _Email);
    void setEstado(bool _Estado);
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