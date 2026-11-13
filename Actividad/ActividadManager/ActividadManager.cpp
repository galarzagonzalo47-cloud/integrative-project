#include "ActividadManager.h"
#include <iostream>
#include <string>

using namespace std;

ActividadManager::ActividadManager(){
    _archivoActividad = ActividadArchivo();
}

void ActividadManager::mostrarMenu(){
    int op;
    do{
        cout<<"BIENVENIDO AL MENU DE GESTION DE ACTIVIDADES"<<endl;
        cout<<"Seleccione algunas de las siguientes opciones: "<<endl;
        cout<<"1. Cargar Actividad"<<endl;
        cout<<"2. Listar Actividades"<<endl;
        cout<<"3. Buscar Actividad Por ID"<<endl;
        cout<<"4. Modificar Actividad"<<endl;
        cout<<"5. Dar de baja Actividad"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cin>>op;
        switch(op){
            case 1:
                cargarActividad();
                break;
            case 2:
                listarActividad();
                break;
            case 3:
                buscarActividad();
                break;
            case 4:
                modificarActividad();
                break;
            case 5:
                darDeBajaActividad();
                break;
            case 0:
                return;
            default:
                cout<<"Opcion invalida, intente nuevamente"<<endl;
        }
    }while(op != 0);
}
void ActividadManager::cargarActividad(){
    Actividad reg;
    int id;
    std::string nombre, descripcion;

    cout<<"Ingresar ID de la actividad: ";
    cin>>id;
    cout<<endl;

    if(_archivoActividad.buscarPorId(id) != -1){
        cout<<"Ya existe una actividad con ese ID"<<endl;
        return;
    }

    reg.setId(id);
    cin.ignore();
    cout<<"Ingresar nombre de la actividad: ";
    getline(cin, nombre);
    reg.setNombre(nombre);

    cout<<"Ingresar descripcion de la actividad: ";
    getline(cin, descripcion);
    reg.setDescripcion(descripcion);

    reg.setEstado(true);

    if(_archivoActividad.guardar(reg)){
        cout<<"Actividad cargada correctamente"<<endl;
    }
    else{
        cout<<"Error al cargar la actividad"<<endl;
    }
}

void ActividadManager::listarActividad(){
    int cantidad = _archivoActividad.getCantidadRegistros();
    int activos = 0;
    for(int i=0; i<cantidad; i++){
        Actividad reg = _archivoActividad.leer(i);
        if(reg.getEstado()){
            reg.mostrar();
            cout<<endl;
            activos++;
        }
    }
    if(activos == 0){
        cout<<"No hay actividades cargadas"<<endl;
    }
}

void ActividadManager::modificarActividad(){
    int id;
    cout<<"Ingrese el ID de la actividad que desea modificar: ";
    cin>>id;
    int pos = _archivoActividad.buscarPorId(id);
    if(pos == -1){
        cout<<"No se encontro la actividad"<<endl;
        return;
    }

    Actividad reg = _archivoActividad.leer(pos);
    reg.mostrar();
    cout<<"Estado: "<<(reg.getEstado() ? "Activo" : "Inactivo")<<endl;

    std::string nombre, descripcion;
    cin.ignore();
    cout<<"Ingrese el nuevo nombre de la actividad: ";
    getline(cin, nombre);
    cout<<"Ingrese la nueva descripcion de la actividad: ";
    getline(cin, descripcion);

    reg.setNombre(nombre);
    reg.setDescripcion(descripcion);

    if(_archivoActividad.modificar(reg, pos)){
        cout<<"Actividad modificada correctamente"<<endl;
    }
    else{
        cout<<"Error al modificar la actividad"<<endl;
    }
}

void ActividadManager::darDeBajaActividad(){
    int id;
    cout<<"Ingrese el ID de la actividad que desea dar de baja: ";
    cin>>id;
    int pos = _archivoActividad.buscarPorId(id);
    if(pos == -1){
        cout<<"No se encontro la actividad"<<endl;
        return;
    }

    Actividad reg = _archivoActividad.leer(pos);
    if(!reg.getEstado()){
        cout<<"La actividad ya esta dada de baja"<<endl;
        return;
    }

    reg.mostrar();
    cout<<"¿Esta seguro que desea dar de baja la actividad? (s/n): ";
    char op;
    cin>>op;
    if(op != 's' && op != 'S'){
        cout<<"Operacion cancelada"<<endl;
        return;
    }

    reg.setEstado(false);
    if(_archivoActividad.modificar(reg, pos)){
        cout<<"Actividad dada de baja correctamente"<<endl;
    }
    else{
        cout<<"Error al dar de baja la actividad"<<endl;
    }
}

void ActividadManager::buscarActividadPorId(int id){
    int pos = _archivoActividad.buscarPorId(id);
    if(pos != -1 && _archivoActividad.leer(pos).getEstado()){
        _archivoActividad.leer(pos).mostrar();
    }
    else{
        cout<<"No se encontro la actividad"<<endl;
    }
}
