#include "ProfesorManager.h"
#include <iostream>
#include <string>

using namespace std;

ProfesorManager::ProfesorManager(){
    _archivoProfesor = ProfesorArchivo();
}

void ProfesorManager::mostrarMenu(){
    int op;
    do{
        cout<<"BIENVENIDO AL MENU DE GESTION DE PROFESORES"<<endl;
        cout<<"Seleccione algunas de las siguientes opciones: "<<endl;
        cout<<"1. Cargar Profesor"<<endl;
        cout<<"2. Listar Profesores"<<endl;
        cout<<"3. Buscar Profesor Por ID o DNI"<<endl;
        cout<<"4. Modificar Profesor"<<endl;
        cout<<"5. Dar de baja Profesor"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cin>>op;
        switch(op){
            case 1:
                cargarProfesor();
                break;
            case 2:
                listarProfesor();
                break;
            case 3:
                buscarProfesor();
                break;
            case 4:
                modificarProfesor();
                break;
            case 5:
                darDeBajaProfesor();
                break;
            case 0:
                return;
            default:
                cout<<"Opcion invalida, intente nuevamente"<<endl;
        }
    }while(op != 0);
}

void ProfesorManager::cargarProfesor(){
    Profesor reg;
    int numProfesor, dni;
    std::string nombre, apellido, telefono, email;

    cout<<"Ingresar numero de profesor: ";
    cin>>numProfesor;
    cout<<endl;

    if(_archivoProfesor.buscarPorId(numProfesor) != -1){
        cout<<"Ya existe un profesor con ese numero"<<endl;
        return;
    }

    cout<<"Ingresar DNI: ";
    cin>>dni;
    cin.ignore();
    cout<<endl;

    cout<<"Ingresar nombre: ";
    getline(cin, nombre);
    cout<<endl;

    cout<<"Ingresar apellido: ";
    getline(cin, apellido);
    cout<<endl;

    cout<<"Ingresar telefono: ";
    getline(cin, telefono);
    cout<<endl;

    cout<<"Ingresar email: ";
    getline(cin, email);
    cout<<endl;

    cout<<"Ingresar fecha de nacimiento: "<<endl;
    Fecha fechaNacimiento;
    fechaNacimiento.cargar();
    cout<<endl;

    bool valido = ValidarProfesor(numProfesor, dni, nombre, apellido, telefono, email, fechaNacimiento);
    if(!valido){
        return;
    }

    reg.setEstado(true);
    reg.setNumProfesor(numProfesor);
    reg.setDni(dni);
    reg.setNombre(nombre);
    reg.setApellido(apellido);
    reg.setTelefono(telefono);
    reg.setEmail(email);
    reg.setFechaNacimiento(fechaNacimiento);

    if(_archivoProfesor.guardar(reg)){
        cout<<"Profesor cargado correctamente"<<endl;
    }
    else{
        cout<<"Error al cargar el profesor"<<endl;
    }
}

void ProfesorManager::listarProfesor(){
    int cantidad = _archivoProfesor.getCantidadDeRegistro();
    int activos = 0;
    for(int i=0; i<cantidad; i++){
        Profesor reg = _archivoProfesor.leer(i);
        if(reg.getEstado()){
            reg.mostrar();
            cout<<endl;
            activos++;
        }
    }
    if(activos == 0){
        cout<<"No hay profesores cargados"<<endl;
    }
}

void ProfesorManager::buscarProfesor(){
    cout<<"Desea buscar al profesor por ID o por DNI?"<<endl;
    cout<<"1. ID"<<endl;
    cout<<"2. DNI"<<endl;
    int op;
    cin>>op;

    int pos;
    if(op == 1){
        int numProfesor;
        cout<<"Ingrese el ID del profesor a buscar: ";
        cin>>numProfesor;
        pos = _archivoProfesor.buscarPorId(numProfesor);
    }
    else if(op == 2){
        int dni;
        cout<<"Ingrese el DNI del profesor a buscar: ";
        cin>>dni;
        pos = _archivoProfesor.buscarPorDni(dni);
    }
    else{
        cout<<"Opcion invalida"<<endl;
        return;
    }

    if(pos != -1 && _archivoProfesor.leer(pos).getEstado()){
        _archivoProfesor.leer(pos).mostrar();
    }
    else{
        cout<<"No se encontro el profesor"<<endl;
    }
}

void ProfesorManager::modificarProfesor(){
    int numProfesor;
    cout<<"Ingrese el numero de profesor que desea modificar: ";
    cin>>numProfesor;
    int pos = _archivoProfesor.buscarPorId(numProfesor);
    if(pos == -1){
        cout<<"No se encontro el profesor"<<endl;
        return;
    }

    Profesor reg = _archivoProfesor.leer(pos);
    reg.mostrar();
    cout<<"Estado: "<<(reg.getEstado() ? "Activo" : "Inactivo")<<endl;

    int op;
    do{
        cout<<"Que desea modificar?"<<endl;
        cout<<"1. DNI"<<endl;
        cout<<"2. Nombre"<<endl;
        cout<<"3. Apellido"<<endl;
        cout<<"4. Telefono"<<endl;
        cout<<"5. Email"<<endl;
        cout<<"6. Fecha de nacimiento"<<endl;
        cout<<"7. Estado"<<endl;
        cout<<"8. Modificar todos los datos"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>op;

        switch(op){
            case 1:{
                int dni;
                cout<<"Ingrese el nuevo DNI: ";
                cin>>dni;
                reg.setDni(dni);
                break;
            }
            case 2:{
                std::string nombre;
                cin.ignore();
                cout<<"Ingrese el nuevo nombre: ";
                getline(cin, nombre);
                reg.setNombre(nombre);
                break;
            }
            case 3:{
                std::string apellido;
                cin.ignore();
                cout<<"Ingrese el nuevo apellido: ";
                getline(cin, apellido);
                reg.setApellido(apellido);
                break;
            }
            case 4:{
                std::string telefono;
                cin.ignore();
                cout<<"Ingrese el nuevo telefono: ";
                getline(cin, telefono);
                reg.setTelefono(telefono);
                break;
            }
            case 5:{
                std::string email;
                cin.ignore();
                cout<<"Ingrese el nuevo email: ";
                getline(cin, email);
                reg.setEmail(email);
                break;
            }
            case 6:{
                Fecha fechaNacimiento;
                cout<<"Ingrese la nueva fecha de nacimiento: "<<endl;
                fechaNacimiento.cargar();
                reg.setFechaNacimiento(fechaNacimiento);
                break;
            }
            case 7:{
                bool estado;
                cout<<"Ingrese el nuevo estado (1 para activo, 0 para inactivo): ";
                cin>>estado;
                reg.setEstado(estado);
                break;
            }
            case 8:{
                int dni;
                std::string nombre, apellido, telefono, email;
                bool estado;
                Fecha fechaNacimiento;

                cout<<"Ingrese el nuevo DNI: ";
                cin>>dni;
                cin.ignore();
                cout<<"Ingrese el nuevo nombre: ";
                getline(cin, nombre);
                cout<<"Ingrese el nuevo apellido: ";
                getline(cin, apellido);
                cout<<"Ingrese el nuevo telefono: ";
                getline(cin, telefono);
                cout<<"Ingrese el nuevo email: ";
                getline(cin, email);
                cout<<"Ingrese el nuevo estado (1 para activo, 0 para inactivo): ";
                cin>>estado;
                cout<<endl;
                cout<<"Ingrese la nueva fecha de nacimiento: "<<endl;
                fechaNacimiento.cargar();

                reg.setDni(dni);
                reg.setNombre(nombre);
                reg.setApellido(apellido);
                reg.setTelefono(telefono);
                reg.setEmail(email);
                reg.setEstado(estado);
                reg.setFechaNacimiento(fechaNacimiento);
                break;
            }
            case 0:
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
        }

        if(op >= 1 && op <= 8){
            bool valido = ValidarProfesor(reg.getNumProfesor(), reg.getDni(), reg.getNombre(), reg.getApellido(),
                                          reg.getTelefono(), reg.getEmail(), reg.getFechaNacimiento(), pos);
            if(!valido){
                reg = _archivoProfesor.leer(pos);
                cout<<"No se guardaron los cambios"<<endl;
            }
            else if(_archivoProfesor.modificar(reg, pos)){
                cout<<"Profesor modificado correctamente"<<endl;
            }
            else{
                cout<<"Error al modificar el profesor"<<endl;
            }
        }
    }while(op != 0);
}

void ProfesorManager::darDeBajaProfesor(){
    int numProfesor;
    cout<<"Ingrese el numero de profesor que desea dar de baja: ";
    cin>>numProfesor;
    int pos = _archivoProfesor.buscarPorId(numProfesor);
    if(pos == -1){
        cout<<"No se encontro el profesor"<<endl;
        return;
    }

    Profesor reg = _archivoProfesor.leer(pos);
    if(!reg.getEstado()){
        cout<<"El profesor ya esta dado de baja"<<endl;
        return;
    }

    reg.mostrar();
    cout<<"¿Esta seguro que desea dar de baja al profesor? (s/n): ";
    char op;
    cin>>op;
    if(op != 's' && op != 'S'){
        cout<<"Operacion cancelada"<<endl;
        return;
    }

    reg.setEstado(false);
    if(_archivoProfesor.modificar(reg, pos)){
        cout<<"Profesor dado de baja correctamente"<<endl;
    }
    else{
        cout<<"Error al dar de baja el profesor"<<endl;
    }
}

bool ProfesorManager::ValidarProfesor(int numProfesor, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNacimiento, int posExcluir){
    if(numProfesor <= 0){
        cout<<"El numero de profesor debe ser mayor a 0"<<endl;
        return false;
    }

    if(dni <= 0 || to_string(dni).length() != 8){
        cout<<"El DNI debe tener exactamente 8 digitos"<<endl;
        return false;
    }

    int posDni = _archivoProfesor.buscarPorDni(dni);
    if(posDni != -1 && posDni != posExcluir){
        cout<<"Ya existe un profesor con ese DNI"<<endl;
        return false;
    }

    if(nombre.empty()){
        cout<<"El nombre no puede estar vacio"<<endl;
        return false;
    }

    if(apellido.empty()){
        cout<<"El apellido no puede estar vacio"<<endl;
        return false;
    }

    if(telefono.empty()){
        cout<<"El telefono no puede estar vacio"<<endl;
        return false;
    }

    if(email.empty()){
        cout<<"El email no puede estar vacio"<<endl;
        return false;
    }

    size_t posArroba = email.find('@');
    size_t posPunto = email.find('.', posArroba);

    if(posArroba == string::npos || posArroba == 0 || posArroba == email.length() - 1
       || posPunto == string::npos || posPunto == posArroba + 1 || posPunto == email.length() - 1){
        cout<<"El email no tiene un formato valido (ejemplo: nombre@dominio.com)"<<endl;
        return false;
    }
    if(fechaNacimiento.getDia() <= 0 || fechaNacimiento.getDia() > 31){
        cout<<"El dia de nacimiento debe estar entre 1 y 31"<<endl;
        return false;
    }
    if(fechaNacimiento.getMes() <= 0 || fechaNacimiento.getMes() > 12){
        cout<<"El mes de nacimiento debe estar entre 1 y 12"<<endl;
        return false;
    }
    if(fechaNacimiento.getAnio() <= 1930){
        cout<<"El anio de nacimiento debe ser mayor a 1930"<<endl;
        return false;
    }
    return true;
}
