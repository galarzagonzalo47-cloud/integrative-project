#include "ProfesorManager.h"

ProfesorManager::ProfesorManager(){
    _archivoProfesor = ProfesorArchivo();
}

void ProfesorManager::mostrarMenu(){
    int op;
    do{cout<<"BIENVENIDO AL MENU DE GESTION DE PROFESORES"<<endl;
    cout<<"Seleccione algunas de las siguientes opciones: "<<endl;
    cout<<"1. Cargar Profesor"<<endl;
    cout<<"2. Listar Profesores"<<endl;
    cout<<"3. Buscar Profesor Por ID o DNI"<<endl;
    cout<<"4. Modificar Profesor"<<endl;
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
    bool estado = false;
    std::string nombre, apellido, telefono, email;
    cout<<"Ingresar numero de profesor: ";
    cin>>numProfesor;
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

    bool valido = ValidarProfesor(numProfesor, dni, nombre, apellido, telefono, email, fechaNacimiento);

    if(!valido){
        return;
    }

    reg.setEstado(true);
    reg.setNumProfesor(numProfesor);
    reg.setDni(dni);
    reg.setNombre(nombre.c_str());
    reg.setApellido(apellido.c_str());
    reg.setTelefono(telefono.c_str());
    reg.setEmail(email.c_str());
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
    if(cantidad == 0){
        cout<<"No hay profesores cargados"<<endl;
        return;
    }
    for(int i=0; i<cantidad; i++){
        Profesor reg = _archivoProfesor.leer(i);
        if(reg.getEstado()){
            cout<<"Numero de profesor: "<<reg.getNumProfesor()<<endl;
            cout<<"DNI: "<<reg.getDni()<<endl;
            cout<<"Nombre: "<<reg.getNombre()<<endl;
            cout<<"Apellido: "<<reg.getApellido()<<endl;
            cout<<"Telefono: "<<reg.getTelefono()<<endl;
            cout<<"Email: "<<reg.getEmail()<<endl;
            cout<<"Fecha de nacimiento: ";
            reg.getFechaNacimiento().mostrar();
            cout<<endl;
        }
    }
}

void ProfesorManager::buscarProfesor(){
    cout<<"Desea buscar al profesor por ID o por DNI?";
    cout<<"1. ID"<<endl;
    cout<<"2. DNI"<<endl;
    int op;
    cin>>op;
    if(op == 1){
        int numProfesor;
        cout<<"Ingrese el ID del profesor a buscar: ";
        cin>>numProfesor;
        int pos = _archivoProfesor.buscarPorId(numProfesor);
        if(pos != -1){
            Profesor reg = _archivoProfesor.leer(pos);
            cout<<"Numero de profesor: "<<reg.getNumProfesor()<<endl;
            cout<<"DNI: "<<reg.getDni()<<endl;
            cout<<"Nombre: "<<reg.getNombre()<<endl;
            cout<<"Apellido: "<<reg.getApellido()<<endl;
            cout<<"Telefono: "<<reg.getTelefono()<<endl;
            cout<<"Email: "<<reg.getEmail()<<endl;
            cout<<"Fecha de nacimiento: ";
            reg.getFechaNacimiento().mostrar();
            cout<<endl;
        }
        else{
            cout<<"No se encontro el profesor"<<endl;
        }
    }
    else if(op == 2){
        int dni;
        cout<<"Ingrese el DNI del profesor a buscar: ";
        cin>>dni;
        int pos = _archivoProfesor.buscarPorDni(dni);
        if(pos != -1){
            Profesor reg = _archivoProfesor.leer(pos);
            cout<<"Numero de profesor: "<<reg.getNumProfesor()<<endl;
            cout<<"DNI: "<<reg.getDni()<<endl;
            cout<<"Nombre: "<<reg.getNombre()<<endl;
            cout<<"Apellido: "<<reg.getApellido()<<endl;
            cout<<"Telefono: "<<reg.getTelefono()<<endl;
            cout<<"Email: "<<reg.getEmail()<<endl;
            cout<<"Fecha de nacimiento: ";
            reg.getFechaNacimiento().mostrar();
            cout<<endl;
        }
        else{
            cout<<"No se encontro el profesor"<<endl;
        }
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

void ProfesorManager::modificarProfesor(){
    int numProfesor;
    cout<<"Ingrese el numero de profesor que desea modificar: ";
    cin>>numProfesor;
    int pos = _archivoProfesor.buscarPorId(numProfesor);
    if(pos != -1){
        Profesor reg = _archivoProfesor.leer(pos);
        cout<<"Numero de profesor: "<<reg.getNumProfesor()<<endl;
        cout<<"DNI: "<<reg.getDni()<<endl;
        cout<<"Nombre: "<<reg.getNombre()<<endl;
        cout<<"Apellido: "<<reg.getApellido()<<endl;
        cout<<"Telefono: "<<reg.getTelefono()<<endl;
        cout<<"Email: "<<reg.getEmail()<<endl;
        cout<<"Fecha de nacimiento: ";
        reg.getFechaNacimiento().mostrar();
        cout<<endl;

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
                    reg.setNombre(nombre.c_str());
                    break;
                }
                case 3:{
                    std::string apellido;
                    cin.ignore();
                    cout<<"Ingrese el nuevo apellido: ";
                    getline(cin, apellido);
                    reg.setApellido(apellido.c_str());
                    break;
                }
                case 4:{
                    std::string telefono;
                    cin.ignore();
                    cout<<"Ingrese el nuevo telefono: ";
                    getline(cin, telefono);
                    reg.setTelefono(telefono.c_str());
                    break;
                }
                case 5:{
                    std::string email;
                    cin.ignore();
                    cout<<"Ingrese el nuevo email: ";
                    getline(cin, email);
                    reg.setEmail(email.c_str());
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
                    reg.setNombre(nombre.c_str());
                    reg.setApellido(apellido.c_str());
                    reg.setTelefono(telefono.c_str());
                    reg.setEmail(email.c_str());
                    reg.setEstado(estado);                
                    reg.setFechaNacimiento(fechaNacimiento);
                }
                case 0:
                break;

                default:
                cout<<"Opcion Invalida"<<endl;
            }

        }while(op != 0);
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
    if (fechaNacimiento.getDia() <= 0 || fechaNacimiento.getDia() > 31){
        cout<<"El dia de nacimiento debe estar entre 1 y 31"<<endl;
        return false;
    }
    if (fechaNacimiento.getMes() <= 0 || fechaNacimiento.getMes() > 12){
        cout<<"El mes de nacimiento debe estar entre 1 y 12"<<endl;
        return false;
    }
    if (fechaNacimiento.getAnio() <= 1930){
        cout<<"El anio de nacimiento debe ser mayor a 1930"<<endl;
        return false;
    }
    return true;
}