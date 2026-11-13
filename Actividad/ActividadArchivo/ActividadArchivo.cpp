#pragma once
#include "ActividadArchivo.h"

ActividadArchivo::ActividadArchivo(){
    _nombreArchivo = "actividades.dat";
}

bool ActividadArchivo::guardar(Actividad reg){
FILE *p = fopen (_nombreArchivo.c_str(),"ab");
if (p=NULL)
{
    cout << "error al guardar el archivo"<< endl;
    return false;
}
bool seGuardo = fwrite (&reg,sizeof(Actividad),1,p);
fclose(p);
return seGuardo;
}

Actividad ActividadArchivo::leer(int pos){
    Actividad aux;
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL){
        cout << "error al leer el archivo" << endl;
        return aux;
    }
    fseek(p, pos * sizeof(Actividad), SEEK_SET);
    fread(&aux, sizeof(Actividad), 1, p);
    fclose(p);
    return aux;
}
int ActividadArchivo::getCantidadRegistros(){
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Actividad);
}

int ActividadArchivo::buscarPorId(int id){
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if(p == NULL){
        return -1;
    }
    Actividad aux;
    int pos = 0;
    while(fread(&aux, sizeof(Actividad), 1, p) == 1){
        if(aux.getNumActividad() == id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
int ActividadArchivo::modificar(Actividad reg, int pos){
    FILE *p = fopen(_nombreArchivo.c_str(), "rb+");
    if(p == NULL){
        return -1;
    }
    fseek(p, pos * sizeof(Actividad), SEEK_SET);
    bool seModifico = fwrite(&reg, sizeof(Actividad), 1, p) == 1;
    fclose(p);
    return seModifico;
}
bool ActividadArchivo::modificar(Actividad reg, int pos){
    FILE *p = fopen(_nombreArchivo.c_str(), "rb+");
    if(p == NULL){
        return false;
    }
    fseek(p, pos * sizeof(Actividad), SEEK_SET);
    bool seModifico = fwrite(&reg, sizeof(Actividad), 1, p) == 1;
    fclose(p);
    return seModifico;
}