#pragma once
#include <string>

class Inscripcion{
    private:
    int _numInscripcion;
    int _numActividad;
    int _numSocio;
    Fecha _fechaInscripcion;
    bool _estado;

    public:
    Inscripcion();
    int getNumInscripcion();
    int getNumActividad();
    int getNumSocio();
    Fecha getFechaInscripcion();
    bool getEstado();

    void setNumInscripcion(int numInscripcion);
    void setNumActividad(int numActividad);
    void setNumSocio(int numSocio);
    void setFechaInscripcion(Fecha fechaInscripcion);
    void setEstado(bool estado);
};

/* NumInscripcion : int
NumActividad : int
NumSocio : int
FechaInscripcion : Fecha
Estado : bool*/