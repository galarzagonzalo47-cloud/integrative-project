#pragma once
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
    Actividad();
    int getNumActividad();
    std::string getNombre();
    int getNumProfesor();
    int getNumDisciplina();
    int getNumSede();
    Fecha getFechaInicio();
    float getArancel();
    int getCupoMaximo();
    bool getEstado();

    void setNumActividad(int numActividad);
    void setNombre(std::string nombre);
    void setNumProfesor(int numProfesor);
    void setNumDisciplina(int numDisciplina);
    void setNumSede(int numSede);
    void setFechaInicio(Fecha fechaInicio);
    void setArancel(float arancel);
    void setCupoMaximo(int cupoMaximo);
    void setEstado(bool estado);
}
