#pragma once
#include <iostream>

class Disciplina{
    private:
    int _numDisciplina;
    char _nombre[40];
    char _descripcion[80];
    bool _estado;

    public:
    Disciplina();
    int getNumDiscplina();
    std::string getNombre();
    std::string getDescripcion();
    bool getEstado();

    void setNumDiscplina(int numDisciplina);
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setEstado(bool estado);
};



/*
Disciplina.dat
NumDisciplina : int
Nombre : char[40]
Descripcion : char[80]
Estado : bool
*/

