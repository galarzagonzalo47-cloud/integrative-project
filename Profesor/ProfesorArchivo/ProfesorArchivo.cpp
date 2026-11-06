#include "ProfesorArchivo.h"

ProfesorArchivo::ProfesorArchivo(){
    _nombreDeArchivo = "Profesor.dat";
}

bool ProfesorArchivo::guardar(Profesor reg){
    FILE *p = fopen (_nombreDeArchivo.c_str(), "ab");
    if( p == NULL){
        cout<<"ERR0R AL GUARDAR EL ARCHIVO DE PROFESOR"<<endl;
        return false;
    }
    bool seGuardo = fwrite (&reg, sizeof(Profesor), 1, p);
    fclose(p);
    return seGuardo;
}

Profesor ProfesorArchivo::leer(int pos){
Profesor aux;
FILE *p = fopen ( _nombreDeArchivo.c_str(), "rb");
if( p == NULL){
        cout<<"ERR0R AL LEER EL ARCHIVO DE PROFESOR"<<endl;
        return aux;
}
fseek(p, pos * sizeof(Profesor), SEEK_SET);
fread (&aux, sizeof(Profesor), 1 ,p);
fclose(p);
return aux;
}

int ProfesorArchivo::getCantidadDeRegistro(){
    FILE *p = fopen (_nombreDeArchivo.c_str(),"rb");
    if(p == NULL){
        cout<<"ERROR AL LEER LOS REGISTRO DE PROFESOR"<<endl;
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Profesor);
}

int ProfesorArchivo::buscarPorId(int id){
    FILE *p = fopen (_nombreDeArchivo.c_str(), "rb");
    if ( p ==NULL){
        cout<<" ERROR AL BUSCAR EL REGISTRO DE PROFESOR "<<endl;
        return -1;
    }
    Profesor aux;
    int pos = 0;
    while (fread(&aux, sizeof(Profesor),1,p)==1){
        if( aux.getNumProfesor()==id){
            fclose(p);
            return pos;
        }
        pos ++;
    }
    fclose(p);
    return -1;
}

int ProfesorArchivo::buscarPorDni(int dni){
    FILE *p = fopen (_nombreDeArchivo.c_str(), "rb");
    if ( p ==NULL){
        cout<<" ERROR AL BUSCAR EL REGISTRO DE PROFESOR "<<endl;
        return -1;
    }
    Profesor aux;
    int pos = 0;
    while (fread(&aux, sizeof(Profesor), 1,p) ==1){
        if( aux.getDni()==dni){
            fclose(p);
            return pos;
        }
        pos ++;
    }
    fclose(p);
    return -1;
}

int ProfesorArchivo::modificarPorId(Profesor reg, int pos){
    FILE *p = fopen ( _nombreDeArchivo.c_str(), "rb+");

    if( p == NULL){
        cout<<"ERROR AL MODIFICAR EL REGISTRO DE PROFESOR"<<endl;
        return -1; 
    }
    fseek (p, pos*sizeof(Profesor), SEEK_SET);
    fwrite (&reg, sizeof(Profesor), 1, p);
    fclose(p);
    return 1;
}