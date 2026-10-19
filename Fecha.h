#include <iostream>

using namespace std;

class Fecha{
    private:
    int _dia;
    int _mes;
    int _anio;

    public:
    void mostrar();
    void cargar();

    int getDia();
    int getMes();
    int getAnio();

    void setDia(int _Dia);
    void setMes(int _Mes);
    void setAnio(int _Anio);

};