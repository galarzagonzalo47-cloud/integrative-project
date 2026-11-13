#include "ProfesorArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

ProfesorArchivo::ProfesorArchivo(){
    _nombreDeArchivo = "Profesor.dat";
}

bool ProfesorArchivo::guardar(Profesor reg){
    FILE *p = fopen(_nombreDeArchivo.c_str(), "ab");
    if(p == NULL){
        cout<<"ERROR AL GUARDAR EL ARCHIVO DE PROFESOR"<<endl;
        return false;
    }
    bool seGuardo = fwrite(&reg, sizeof(Profesor), 1, p) == 1;
    fclose(p);
    return seGuardo;
}

Profesor ProfesorArchivo::leer(int pos){
    Profesor aux;
    FILE *p = fopen(_nombreDeArchivo.c_str(), "rb");
    if(p == NULL){
        cout<<"ERROR AL LEER EL ARCHIVO DE PROFESOR"<<endl;
        return aux;
    }
    fseek(p, pos * sizeof(Profesor), SEEK_SET);
    fread(&aux, sizeof(Profesor), 1, p);
    fclose(p);
    return aux;
}

int ProfesorArchivo::getCantidadDeRegistro(){
    FILE *p = fopen(_nombreDeArchivo.c_str(), "rb");
    if(p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Profesor);
}

int ProfesorArchivo::buscarPorId(int id){
    FILE *p = fopen(_nombreDeArchivo.c_str(), "rb");
    if(p == NULL){
        return -1;
    }
    Profesor aux;
    int pos = 0;
    while(fread(&aux, sizeof(Profesor), 1, p) == 1){
        if(aux.getNumProfesor() == id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

int ProfesorArchivo::buscarPorDni(int dni){
    FILE *p = fopen(_nombreDeArchivo.c_str(), "rb");
    if(p == NULL){
        return -1;
    }
    Profesor aux;
    int pos = 0;
    while(fread(&aux, sizeof(Profesor), 1, p) == 1){
        if(aux.getDni() == dni){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool ProfesorArchivo::modificar(Profesor reg, int pos){
    FILE *p = fopen(_nombreDeArchivo.c_str(), "rb+");
    if(p == NULL){
        cout<<"ERROR AL MODIFICAR EL REGISTRO DE PROFESOR"<<endl;
        return false;
    }
    fseek(p, pos * sizeof(Profesor), SEEK_SET);
    bool seModifico = fwrite(&reg, sizeof(Profesor), 1, p) == 1;
    fclose(p);
    return seModifico;
}
