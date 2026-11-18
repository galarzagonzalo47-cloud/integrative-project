#include "DisciplinaManager.h"
#include <iostream>

using namespace std;

DisciplinaManager::DisciplinaManager(){
    _archivo = DisciplinaArchivo();
}

void DisciplinaManager::mostrarMenu(){
    int op;
    do{
        cout<<"BIENVENIDO AL MENU DE GESTION DE DISCIPLINAS"<<endl;
        cout<<"Seleccione algunas de las siguientes opciones: "<<endl;
        cout<<"1. Cargar Disciplina"<<endl;
        cout<<"2. Listar Disciplinas"<<endl;
        cout<<"3. Buscar Disciplina Por ID"<<endl;
        cout<<"4. Modificar Disciplina"<<endl;
        cout<<"5. Dar de baja Disciplina"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cin>>op;
        switch(op){
            case 1:
                cargarDisciplina();
                break;
            case 2:
                listarDisciplina();
                break;
            case 3:
                buscarDisciplina();
                break;
            case 4:
                modificarDisciplina();
                break;
            case 5:
                darDeBajaDisciplina();
                break;
            case 0:
                return;
            default:
                cout<<"Opcion invalida, intente nuevamente"<<endl;
        }
    }while(op != 0);
}

void DisciplinaManager::cargarDisciplina(){
    Disciplina reg;
    int numDisciplina;
    std::string nombre, descripcion;

    cout<<"Ingresar numero de disciplina: ";
    cin>>numDisciplina;
    cin.ignore();
    cout<<endl;

    if(_archivo.buscarPorId(numDisciplina) != -1){
        cout<<"Ya existe una disciplina con ese numero"<<endl;
        return;
    }

    cout<<"Ingresar nombre: ";
    getline(cin, nombre);
    cout<<endl;

    cout<<"Ingresar descripcion: ";
    getline(cin, descripcion);
    cout<<endl;

    reg.setNumDiscplina(numDisciplina);
    reg.setNombre(nombre);
    reg.setDescripcion(descripcion);
    reg.setEstado(true);

    if(_archivo.guardar(reg)){
        cout<<"Se guardo correctamente"<<endl;
    }
    else{
        cout<<"No se pudo guardar"<<endl;
    }
}

void DisciplinaManager::listarDisciplina(){
    int cantidad = _archivo.getCantidadRegistros();
    int activas = 0;
    for(int i=0; i<cantidad; i++){
        Disciplina reg = _archivo.leer(i);
        if(reg.getEstado()){
            cout<<"Numero de disciplina: "<<reg.getNumDiscplina()<<endl;
            cout<<"Nombre: "<<reg.getNombre()<<endl;
            cout<<"Descripcion: "<<reg.getDescripcion()<<endl;
            cout<<endl;
            activas++;
        }
    }
    if(activas == 0){
        cout<<"No hay disciplinas cargadas"<<endl;
    }
}

void DisciplinaManager::buscarDisciplina(){
    int numDisciplina;
    cout<<"Ingrese el id de disciplina que desea buscar: ";
    cin>>numDisciplina;
    int pos = _archivo.buscarPorId(numDisciplina);
    if(pos != -1){
        Disciplina reg = _archivo.leer(pos);
        cout<<"Numero de disciplina: "<<reg.getNumDiscplina()<<endl;
        cout<<"Nombre: "<<reg.getNombre()<<endl;
        cout<<"Descripcion: "<<reg.getDescripcion()<<endl;
        cout<<"Estado: "<<(reg.getEstado() ? "Activo" : "Inactivo")<<endl;
    }
    else{
        cout<<"No se encontro la disciplina"<<endl;
    }
}

void DisciplinaManager::modificarDisciplina(){
    int numDisciplina;
    cout<<"Ingrese el numero de disciplina que desea modificar: ";
    cin>>numDisciplina;
    int pos = _archivo.buscarPorId(numDisciplina);
    if(pos == -1){
        cout<<"No se encontro la disciplina"<<endl;
        return;
    }

    Disciplina reg = _archivo.leer(pos);
    cout<<"Numero de disciplina: "<<reg.getNumDiscplina()<<endl;
    cout<<"Nombre: "<<reg.getNombre()<<endl;
    cout<<"Descripcion: "<<reg.getDescripcion()<<endl;
    cout<<"Estado: "<<(reg.getEstado() ? "Activo" : "Inactivo")<<endl;

    int op;
    do{
        cout<<"Que desea modificar?"<<endl;
        cout<<"1. Nombre"<<endl;
        cout<<"2. Descripcion"<<endl;
        cout<<"3. Estado"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>op;

        switch(op){
            case 1:{
                std::string nombre;
                cin.ignore();
                cout<<"Ingrese el nuevo nombre: ";
                getline(cin, nombre);
                reg.setNombre(nombre);
                break;
            }
            case 2:{
                std::string descripcion;
                cin.ignore();
                cout<<"Ingrese la nueva descripcion: ";
                getline(cin, descripcion);
                reg.setDescripcion(descripcion);
                break;
            }
            case 3:{
                bool estado;
                cout<<"Ingrese el nuevo estado (1 para activo, 0 para inactivo): ";
                cin>>estado;
                reg.setEstado(estado);
                break;
            }
            case 0:
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
        }

        if(op >= 1 && op <= 3){
            if(_archivo.modificar(reg, pos)){
                cout<<"Disciplina modificada correctamente"<<endl;
            }
            else{
                cout<<"Error al modificar la disciplina"<<endl;
            }
        }
    }while(op != 0);
}

void DisciplinaManager::darDeBajaDisciplina(){
    int numDisciplina;
    cout<<"Ingrese el numero de disciplina que desea dar de baja: ";
    cin>>numDisciplina;
    int pos = _archivo.buscarPorId(numDisciplina);
    if(pos == -1){
        cout<<"No se encontro la disciplina"<<endl;
        return;
    }

    Disciplina reg = _archivo.leer(pos);
    if(!reg.getEstado()){
        cout<<"La disciplina ya esta dada de baja"<<endl;
        return;
    }

    cout<<"Numero de disciplina: "<<reg.getNumDiscplina()<<endl;
    cout<<"Nombre: "<<reg.getNombre()<<endl;
    cout<<"Descripcion: "<<reg.getDescripcion()<<endl;
    cout<<"¿Esta seguro que desea dar de baja la disciplina? (s/n): ";
    char op;
    cin>>op;
    if(op != 's' && op != 'S'){
        cout<<"Operacion cancelada"<<endl;
        return;
    }

    reg.setEstado(false);
    if(_archivo.modificar(reg, pos)){
        cout<<"Disciplina dada de baja correctamente"<<endl;
    }
    else{
        cout<<"Error al dar de baja la disciplina"<<endl;
    }
}
