#include "SociosArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

SociosArchivo::SociosArchivo(){
    _nombreArchivo = "Socios.dat";
}

bool SociosArchivo::guardar(Socios reg){
    FILE *p = fopen (_nombreArchivo.c_str(), "ab"); //Abrimos el archivo binario en modo append (agregar al final). Si no existe, lo crea

    if( p == NULL){
        cout<<"Error al guardar el archivo"<<endl;
        return false;
    }
    bool seGuardo = fwrite(&reg, sizeof(Socios),1, p) == 1; //fwrite devuelve la cantidad de registros que pudo escribir
    fclose(p);
    return seGuardo; //Devolvemos true si se guardo correctamente, false si no
}

Socios SociosArchivo::leer(int pos){
    Socios aux;
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb");
    if( p==NULL){
        return aux; //Si no se pudo abrir el archivo, devolvemos un registro vacio
    }
    fseek(p, pos * sizeof(Socios), SEEK_SET); //Nos posicionamos en el registro que queremos leer, pos * sizeof(Socios) nos da la cantidad de bytes desde el inicio del archivo
    fread(&aux, sizeof(Socios), 1, p); //Leemos el registro y lo guardamos en aux
    fclose(p);
    return aux;
}

int SociosArchivo::getCantidadRegistros(){
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb");
    if ( p ==NULL ){
        return 0; //Si el archivo todavia no existe, no hay registros
    }
    fseek(p, 0, SEEK_END); //Nos posicionamos al final del archivo
    int bytes = ftell(p); //ftell nos devuelve la cantidad de bytes desde el inicio del archivo hasta la posicion actual (final del archivo)
    fclose(p);
    return bytes / sizeof(Socios); //Devolvemos la cantidad de registros dividiendo la cantidad de bytes entre el tamaño de un registro
}

int SociosArchivo::buscarPorID(int id){
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb");
    if ( p ==NULL ){
        return -1; //Si el archivo no existe, no hay nada que buscar
    }
    Socios aux;
    int pos = 0;
    while ( fread(&aux, sizeof(Socios), 1, p)==1 ){
        if ( aux.getNumSocio() == id ){ //Si el ID del registro que leimos es igual al ID que estamos buscando, devolvemos la posicion del registro
            fclose(p);
            return pos;
        }
        pos++; //Si no es igual, seguimos buscando y aumentamos la posicion
    }
    fclose(p);
    return -1; //Si no se encontro el registro, devolvemos -1
}

int SociosArchivo::buscarPorDni(int dni){
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb");
    if ( p ==NULL ){
        return -1; //Si el archivo no existe, no hay nada que buscar
    }
    Socios aux;
    int pos = 0;
    while ( fread(&aux, sizeof(Socios), 1, p)==1 ){
        if ( aux.getDni() == dni ){ //Si el DNI del registro que leimos es igual al DNI que estamos buscando, devolvemos la posicion del registro
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1; //Si no se encontro el registro, devolvemos -1
}

bool SociosArchivo::modificar(Socios reg, int pos){
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb+"); //rb+ abre para leer y escribir sin borrar el contenido
    if (p == NULL){
        cout<<"Error al modificar el registro"<<endl;
        return false;
    }
    fseek(p, pos * sizeof(Socios), SEEK_SET);
    bool seModifico = fwrite (&reg, sizeof(Socios), 1, p) == 1;
    fclose(p);
    return seModifico;
}
