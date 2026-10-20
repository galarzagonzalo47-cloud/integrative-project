#include "SociosArchivo.h"

SociosArchivo::SociosArchivo(){
    _nombreArchivo = "Socios.dat";
}

bool SociosArchivo::guardar(Socios reg){
    FILE *p = fopen (_nombreArchivo.c_str(), "ab"); //Creamos el archivo en modo append (agregar al final) -> ap = append binary ( ABRIR ARCHIVO BINARIO PARA AGREGAR AL FINAL)

    if( p == NULL){
        cout<<"Error al guardar el archivo"<<endl;
        return false;
    }
    bool seGuardo = fwrite(&reg, sizeof(Socios),1, p); //Con fwrite guardamos el registro en el archivo, le pasamos la direccion de memoria del registro, el tamaño del registro y la cantidad de registros a guardar (1)
    fclose(p);
    return seGuardo; //Devolvemos true si se guardo correctamente, false si no
}

Socios SociosArchivo::leer(int pos){
    Socios aux;
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb");
    if( p==NULL){
        cout<<"Error al leer el archivo"<<endl;
        return aux; //Si no se pudo abrir el archivo, devolvemos un registro vacio
    }
    fseek(p, pos * sizeof(Socios), SEEK_SET); //Nos posicionamos en la posicion del registro que queremos leer, pos * sizeof(Socios) nos da la cantidad de bytes que tenemos que movernos desde el inicio del archivo
    fread(&aux, sizeof(Socios), 1, p); //Leemos el registro y lo guardamos en aux
    fclose(p);
    return aux;
}

int SociosArchivo::getCantidadRegistros(){
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb");
    if ( p ==NULL ){
        cout<<"Error al leer la cantidad de registros del archivo"<<endl;
        return 0; //Si no se pudo abrir el archivo, devolvemos 0
    }
    fseek(p, 0, SEEK_END); //Nos posicionamos al final del archivo
    int bytes = ftell(p); //ftell nos devuelve la cantidad de bytes desde el inicio del archivo hasta la posicion actual (final del archivo)
    fclose(p);
    return bytes / sizeof(Socios); //Devolvemos la cantidad de registros dividiendo la cantidad de bytes entre el tamaño de un registro
}

int SociosArchivo::buscarPorID(int id){
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb");
    if ( p ==NULL ){
        cout<<"Error al buscar el registro"<<endl;
        return -1; //Si no se pudo abrir el archivo, devolvemos -1
    }
    Socios aux;
    int pos = 0; //
    while ( fread(&aux, sizeof(Socios), 1, p) ){
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
        cout<<"Error al buscar el registro"<<endl;
        return -1; //Si no se pudo abrir el archivo, devolvemos -1
    }
    Socios aux;
    int pos = 0;
    while ( fread(&aux, sizeof(Socios), 1, p) ){
        if ( aux.getDni() == dni ){ //Si el DNI del registro que leimos es igual al DNI que estamos buscando, devolvemos la posicion del registro
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1; //Si no se encontro el registro, devolvemos -1
}

int SociosArchivo::modificar(Socios reg, int pos){
    FILE *p = fopen ( _nombreArchivo.c_str(), "rb+");
    if (p == NULL){
        cout<<"Error al modificar el registro"<<endl;
        return -1; //Si no se pudo abrir el archivo, devolvemos -1
    }
    fseek(p, pos * sizeof(Socios), SEEK_SET); 
    fwrite (&reg, sizeof(Socios), 1, p);
    fclose(p);
    return 1;
}