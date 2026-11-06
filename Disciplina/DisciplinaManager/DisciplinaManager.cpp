#include "DisciplinaManager.h"

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
    bool estado = false;

    cout<<"Ingresar numero de disciplina: ";
    cin>>numDisciplina;
    cin.ignore();
    cout<<endl;

    cout<<"Ingresar nombre: ";
    getline(cin, nombre);
    cout<<endl;

    cout<<"Ingresar descripcion: ";
    getline(cin, descripcion);
    cout<<endl;

    reg.setNumDiscplina(numDisciplina);
    reg.setNombre(nombre.c_str());
    reg.setDescripcion(descripcion.c_str());
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
    if(cantidad == 0){
        cout<<"No hay disciplinas cargadas"<<endl;
        return;
    }
    for(int i=0; i<cantidad; i++){
        Disciplina reg = _archivo.leer(i);
        if(reg.getEstado()){
            cout<<"Numero de disciplina: "<<reg.getNumDiscplina()<<endl;
            cout<<"Nombre: "<<reg.getNombre()<<endl;
            cout<<"Descripcion: "<<reg.getDescripcion()<<endl;
            cout<<"Estado: "<<(reg.getEstado() ? "Activo" : "Inactivo")<<endl;
            cout<<endl;
        }
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
    int numDiscipliana;
    cout<<"Ingrese el numero de disciplina que desea modificar: ";
    cin>>numDiscipliana;
    int pos = _archivo.buscarPorId(numDiscipliana);
    if(pos != -1){
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
                    reg.setNombre(nombre.c_str());
                    break;
                }
                case 2:{
                    std::string descripcion;
                    cin.ignore();
                    cout<<"Ingrese la nueva descripcion: ";
                    getline(cin, descripcion);
                    reg.setDescripcion(descripcion.c_str());
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
        }while(op != 0);
    }
}