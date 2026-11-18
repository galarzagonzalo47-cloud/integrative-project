#pragma once
#include "Fecha.h"
#include <string>

class Actividad{
    private:
    int _numActividad;
    char _nombre[40];
    int _numProfesor;
    int _numDisciplina;
    int _numSede;
    Fecha _fechaInicio;
    float _arancel;
    int _cupoMaximo;
    bool _estado;

    public:

};

/*
NumActividad : int
Nombre : char[40]
NumProfesor : int
NumDisciplina : int
NumSede : int
FechaInicio : Fecha
Arancel : float
CupoMaximo : int
Estado : bool
*/