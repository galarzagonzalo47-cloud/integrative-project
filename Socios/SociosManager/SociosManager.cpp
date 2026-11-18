#include "SociosManager.h"
#include <iostream>
#include <string>

using namespace std;

SociosManager::SociosManager(){
    _archivo = SociosArchivo();
}

void SociosManager::mostrarMenu(){
    int op;
    do{
        cout<<"BIENVENIDO AL MENU DE GESTION DE SOCIOS"<<endl;
        cout<<"Seleccione algunas de las siguientes opciones: "<<endl;
        cout<<"1. Cargar Socios"<<endl;
        cout<<"2. Listar Socios"<<endl;
        cout<<"3. Buscar Socios Por ID o DNI"<<endl;
        cout<<"4. Modificar Socios"<<endl;
        cout<<"5. Dar de baja Socio"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cin>>op;
        switch(op){
            case 1:
                cargarSocios();
                break;
            case 2:
                listarSocios();
                break;
            case 3:
                buscarSocios();
                break;
            case 4:
                modificarSocios();
                break;
            case 5:
                darDeBajaSocio();
                break;
            case 0:
                return;
            default:
                cout<<"Opcion invalida, intente nuevamente"<<endl;
        }
    }while(op != 0);
}

void SociosManager::cargarSocios(){
    Socios reg;
    int numSocio, dni;
    std::string nombre, apellido, telefono, email;

    cout<<"Ingresar numero de socio: ";
    cin>>numSocio;
    cout<<endl;

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

    bool valido = ValidarSocio(numSocio, dni, nombre, apellido, telefono, email, fechaNacimiento);
    if(!valido){
        cout<<"Error al validar el socio"<<endl;
        return;
    }

    reg.setEstado(true);
    reg.setNumSocio(numSocio);
    reg.setDni(dni);
    reg.setNombre(nombre);
    reg.setApellido(apellido);
    reg.setTelefono(telefono);
    reg.setEmail(email);
    reg.setFechaNacimiento(fechaNacimiento);

    if(_archivo.guardar(reg)){
        cout<<"Socio cargado correctamente"<<endl;
    }
    else{
        cout<<"Error al cargar el socio"<<endl;
    }
}

void SociosManager::listarSocios(){
    int cantidad = _archivo.getCantidadRegistros();
    int activos = 0;
    for(int i = 0; i < cantidad; i++){
        Socios reg = _archivo.leer(i);
        if(reg.getEstado()){
            reg.mostrar();
            cout<<endl;
            activos++;
        }
    }
    if(activos == 0){
        cout<<"No hay socios cargados"<<endl;
    }
}

void SociosManager::buscarSocios(){
    cout<<"Desea buscar al socio por numero de socio o por DNI?"<<endl;
    cout<<"1. Numero de socio"<<endl;
    cout<<"2. DNI"<<endl;
    int op;
    cin>>op;
    if(op == 1){
        buscarSocioPorID();
    }
    else if(op == 2){
        buscarSocioPorDni();
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

void SociosManager::buscarSocioPorID(){
    int numSocio;
    cout<<"Ingrese el ID del socio a buscar: ";
    cin>>numSocio;
    int pos = _archivo.buscarPorID(numSocio);
    if(pos != -1 && _archivo.leer(pos).getEstado()){
        _archivo.leer(pos).mostrar();
    }
    else{
        cout<<"No se encontro el socio"<<endl;
    }
}

void SociosManager::buscarSocioPorDni(){
    int dni;
    cout<<"Ingrese el DNI del socio a buscar: ";
    cin>>dni;
    int pos = _archivo.buscarPorDni(dni);
    if(pos != -1 && _archivo.leer(pos).getEstado()){
        _archivo.leer(pos).mostrar();
    }
    else{
        cout<<"No se encontro el socio"<<endl;
    }
}

void SociosManager::modificarSocios(){
    int numSocio;
    cout<<"Ingrese el Numero de socio que desea modificar: ";
    cin>>numSocio;
    int pos = _archivo.buscarPorID(numSocio);
    if(pos == -1){
        cout<<"No se encontro el socio"<<endl;
        return;
    }

    Socios reg = _archivo.leer(pos);
    reg.mostrar();
    cout<<"Estado del socio: "<<(reg.getEstado() ? "ACTIVO" : "INACTIVO")<<endl;

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
        cout<<"8. Modificar todo"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>op;
        cin.ignore(); // Limpiar el buffer de entrada antes de usar getline

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
                cout<<"Ingrese el nuevo nombre: ";
                getline(cin, nombre);
                reg.setNombre(nombre);
                break;
            }
            case 3:{
                std::string apellido;
                cout<<"Ingrese el nuevo apellido: ";
                getline(cin, apellido);
                reg.setApellido(apellido);
                break;
            }
            case 4:{
                std::string telefono;
                cout<<"Ingrese el nuevo telefono: ";
                getline(cin, telefono);
                reg.setTelefono(telefono);
                break;
            }
            case 5:{
                std::string email;
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
                cin.ignore(); // Limpiar el buffer de entrada antes de usar getline
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
                cout<<"Opcion invalida"<<endl;
        }

        if(op >= 1 && op <= 8){
            bool valido = ValidarSocio(reg.getNumSocio(), reg.getDni(), reg.getNombre(), reg.getApellido(),
                                       reg.getTelefono(), reg.getEmail(), reg.getFechaNacimiento(), pos);
            if(!valido){
                cout<<"No se guardaron los cambios, datos invalidos"<<endl;
                reg = _archivo.leer(pos);
            }
            else if(_archivo.modificar(reg, pos)){
                cout<<"Socio modificado correctamente"<<endl;
            }
            else{
                cout<<"Error al modificar el socio"<<endl;
            }
        }
    }while(op != 0);
}

void SociosManager::darDeBajaSocio(){
    int numSocio;
    cout<<"Ingrese el numero de socio que desea dar de baja: ";
    cin>>numSocio;
    int pos = _archivo.buscarPorID(numSocio);
    if(pos == -1){
        cout<<"No se encontro el socio"<<endl;
        return;
    }

    Socios reg = _archivo.leer(pos);
    if(!reg.getEstado()){
        cout<<"El socio ya esta dado de baja"<<endl;
        return;
    }

    reg.mostrar();
    cout<<"¿Esta seguro que desea dar de baja al socio? (s/n): ";
    char op;
    cin>>op;
    if(op != 's' && op != 'S'){
        cout<<"Operacion cancelada"<<endl;
        return;
    }

    reg.setEstado(false);
    if(_archivo.modificar(reg, pos)){
        cout<<"Socio dado de baja correctamente"<<endl;
    }
    else{
        cout<<"Error al dar de baja el socio"<<endl;
    }
}

bool SociosManager::ValidarSocio(int numSocio, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNacimiento, int posExcluir){
    if(numSocio <= 0){
        cout<<"El numero de socio debe ser mayor a 0"<<endl;
        return false;
    }

    int posNumSocio = _archivo.buscarPorID(numSocio);
    if(posNumSocio != -1 && posNumSocio != posExcluir){
        cout<<"Ya existe un socio con ese numero de socio"<<endl;
        return false;
    }

    if(dni <= 0 || to_string(dni).length() != 8){
        cout<<"El DNI debe tener exactamente 8 digitos"<<endl;
        return false;
    }

    int posDni = _archivo.buscarPorDni(dni);
    if(posDni != -1 && posDni != posExcluir){
        cout<<"Ya existe un socio con ese DNI"<<endl;
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
