#include "Fecha.h"


Fecha::Fecha(){
  _dia = 1;
  _mes = 1;
  _anio = 1;
}



void Fecha::mostrar(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio;
}
void Fecha::cargar(){  
        cout<<"Ingrese el dia: ";
        cin>> _dia;
        cout<<"Ingrese el mes: ";
        cin>>_mes;
        cout<<"Ingrese el anio: ";
        cin>>_anio;
}

int Fecha::getDia(){
        return _dia;
    }
int Fecha::getMes(){
        return _mes;
    }
int Fecha::getAnio(){
        return _anio;
    }

void  Fecha::setDia(int _Dia){
        _dia = _Dia;
    }
void  Fecha::setMes(int _Mes){
        _mes = _Mes;
    }
void  Fecha::setAnio(int _Anio){
        _anio = _Anio;
    }