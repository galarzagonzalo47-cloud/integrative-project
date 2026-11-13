#include "DisciplinaArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

DisciplinaArchivo::DisciplinaArchivo(){
    _nombreArchivo= "Disciplina.dat";
}

bool DisciplinaArchivo::guardar(Disciplina disciplina){
    FILE *p;
    p=fopen(_nombreArchivo.c_str(),"ab");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    bool seGuardo=fwrite(&disciplina, sizeof(Disciplina),1,p);
    fclose(p);
    return seGuardo;
}

Disciplina DisciplinaArchivo::leer(int pos){
    Disciplina aux;
    FILE *p = fopen(_nombreArchivo.c_str(),"rb");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return aux;
    }
    fseek(p,pos*sizeof(Disciplina),SEEK_SET);
    fread(&aux,sizeof(Disciplina),1,p);
    fclose(p);
    return aux;
}

bool DisciplinaArchivo::modificar(Disciplina disciplina, int pos){
    FILE *p = fopen(_nombreArchivo.c_str(),"rb+");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }
    fseek(p,pos*sizeof(Disciplina),SEEK_SET);
    bool seModifico=fwrite(&disciplina,sizeof(Disciplina),1,p);
    fclose(p);
    return seModifico;
}

int DisciplinaArchivo::getCantidadRegistros(){
    FILE *p = fopen(_nombreArchivo.c_str(),"rb");
    if(p==NULL){
        return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes=ftell(p);
    fclose(p);
    return bytes/sizeof(Disciplina);
}

int DisciplinaArchivo::buscarPorId(int id){
    FILE *p = fopen(_nombreArchivo.c_str(),"rb");
    if(p==NULL){
        return -1;
    }
    Disciplina aux;
    int pos=0;
    while(fread(&aux,sizeof(Disciplina),1,p)==1){
        if(aux.getNumDiscplina()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
