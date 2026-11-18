#include "SedesManager.h"
#include <iostream>
#include <limits>

using namespace std;

int SedesManager::pedirOpcion(){
    int op;
    while(!(cin >> op)){
        if(cin.eof()){
            return 0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un numero valido: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return op;
}

void SedesManager::mostrarMenu(){
    int op;
    do{
        cout << endl;
        cout << "BIENVENIDO AL MENU DE GESTION DE SEDES" << endl;
        cout << "Seleccione algunas de las siguientes opciones: " << endl;
        cout << "1. Cargar Sedes" << endl;
        cout << "2. Listar Sedes" << endl;
        cout << "3. Buscar Sedes Por ID o Nombre" << endl;
        cout << "4. Modificar Sedes" << endl;
        cout << "5. Dar de baja Sede" << endl;
        cout << "0. Volver al menu principal" << endl;
        op = pedirOpcion();
        switch(op){
            case 1:
                cargarSedes();
                break;
            case 2:
                listarSedes();
                break;
            case 3:
                buscarSedes();
                break;
            case 4:
                modificarSedes();
                break;
            case 5:
                darDeBajaSede();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida, intente nuevamente" << endl;
        }
    }while(op != 0);
}

void SedesManager::cargarSedes(){
    Sedes reg;
    string nombre, direccion, telefono;

    cout << "Ingresar nombre de la sede: ";
    getline(cin, nombre);
    cout << "Ingresar direccion de la sede: ";
    getline(cin, direccion);
    cout << "Ingresar telefono de la sede: ";
    getline(cin, telefono);

    reg.setId(_archivo.getCantidadRegistros() + 1);
    reg.setNombre(nombre);
    reg.setDireccion(direccion);
    reg.setTelefono(telefono);
    reg.setEstado(true);

    if(_archivo.guardar(reg)){
        cout << "Sede cargada correctamente con ID " << reg.getId() << endl;
    }
    else{
        cout << "Error al cargar la sede" << endl;
    }
}

void SedesManager::listarSedes(){
    int cantidad = _archivo.getCantidadRegistros();
    int activas = 0;
    for(int i = 0; i < cantidad; i++){
        Sedes reg = _archivo.leer(i);
        if(reg.getEstado()){
            reg.mostrar();
            activas++;
        }
    }
    if(activas == 0){
        cout << "No hay sedes cargadas" << endl;
    }
}

void SedesManager::buscarSedes(){
    cout << "Desea buscar la sede por ID o por nombre?" << endl;
    cout << "1. ID" << endl;
    cout << "2. Nombre" << endl;
    int op = pedirOpcion();
    if(op == 1){
        buscarSedePorID();
    }
    else if(op == 2){
        buscarSedePorNombre();
    }
    else{
        cout << "Opcion invalida" << endl;
    }
}

void SedesManager::buscarSedePorID(){
    cout << "Ingrese el ID de la sede a buscar: ";
    int id = pedirOpcion();
    int pos = _archivo.buscarPorID(id);
    if(pos != -1 && _archivo.leer(pos).getEstado()){
        _archivo.leer(pos).mostrar();
    }
    else{
        cout << "No se encontro la sede" << endl;
    }
}

void SedesManager::buscarSedePorNombre(){
    string nombre;
    cout << "Ingrese el nombre de la sede a buscar: ";
    getline(cin, nombre);
    int pos = _archivo.buscarPorNombre(nombre);
    if(pos != -1){
        _archivo.leer(pos).mostrar();
    }
    else{
        cout << "No se encontro la sede" << endl;
    }
}

void SedesManager::modificarSedes(){
    cout << "Ingrese el ID de la sede que desea modificar: ";
    int id = pedirOpcion();
    int pos = _archivo.buscarPorID(id);
    if(pos == -1){
        cout << "No se encontro la sede" << endl;
        return;
    }

    Sedes reg = _archivo.leer(pos);
    if(!reg.getEstado()){
        cout << "La sede esta dada de baja, no se puede modificar" << endl;
        return;
    }
    reg.mostrar();

    string valor;
    cout << "Nuevo nombre (Enter para dejarlo igual): ";
    getline(cin, valor);
    if(!valor.empty()) reg.setNombre(valor);

    cout << "Nueva direccion (Enter para dejarla igual): ";
    getline(cin, valor);
    if(!valor.empty()) reg.setDireccion(valor);

    cout << "Nuevo telefono (Enter para dejarlo igual): ";
    getline(cin, valor);
    if(!valor.empty()) reg.setTelefono(valor);

    if(_archivo.modificar(reg, pos)){
        cout << "Sede modificada correctamente" << endl;
    }
    else{
        cout << "Error al modificar la sede" << endl;
    }
}

void SedesManager::darDeBajaSede(){
    cout << "Ingrese el ID de la sede que desea dar de baja: ";
    int id = pedirOpcion();
    int pos = _archivo.buscarPorID(id);
    if(pos == -1){
        cout << "No se encontro la sede" << endl;
        return;
    }

    Sedes reg = _archivo.leer(pos);
    if(!reg.getEstado()){
        cout << "La sede ya esta dada de baja" << endl;
        return;
    }
    reg.mostrar();

    cout << "¿Esta seguro que desea dar de baja la sede? (s/n): ";
    string respuesta;
    getline(cin, respuesta);
    if(respuesta != "s" && respuesta != "S"){
        cout << "Operacion cancelada" << endl;
        return;
    }

    reg.setEstado(false);
    if(_archivo.modificar(reg, pos)){
        cout << "Sede dada de baja correctamente" << endl;
    }
    else{
        cout << "Error al dar de baja la sede" << endl;
    }
}
