#include "SociosManager.h"
#include "Migrador.h"

SociosManager::SociosManager(){
    _archivo = SociosArchivo();
}

void SociosManager::cargarSocios(){
    Socios reg;
    int numSocio, dni;
    bool estado = false;
    std::string nombre, apellido, telefono, email;
    cout<<"Ingresar numero de socio: ";
    cin>>numSocio;
    cout<<endl;

    cout<<"Ingresar DNI: ";
    cin>>dni;
    cin.ignore(); // Limpiar el buffer de entrada antes de usar getline
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
        return;
    }

    reg.setEstado(true);
    reg.setNumSocio(numSocio);
    reg.setDni(dni);
    reg.setNombre(nombre.c_str());
    reg.setApellido(apellido.c_str());
    reg.setTelefono(telefono.c_str());
    reg.setEmail(email.c_str());
    reg.setFechaNacimiento(fechaNacimiento);


    if(_archivo.guardar(reg)){
        cout<<"Socio cargado correctamente"<<endl;
    }
    else{
        cout<<"Error al cargar el socio"<<endl;
    }

}

void SociosManager::listarSocios(){
    Socios reg;
    int cantidad = _archivo.getCantidadRegistros();
    for( int i = 0; i < cantidad;  i++){
        reg = _archivo.leer(i);
        cout<<"========================================"<<endl;
        cout<<"Numero de socio: "<<reg.getNumSocio()<<endl;
        cout<<"DNI del socio: "<<reg.getDni()<<endl;
        cout<<"Nombre del socio: "<<reg.getNombre()<<endl;
        cout<<"Apellido del socio: "<<reg.getApellido()<<endl;
        cout<<"Telefono del socio: "<<reg.getTelefono()<<endl;
        cout<<"Email del socio: "<<reg.getEmail()<<endl;
        cout<<"Fecha de nacimiento del socio:"<<endl;
        cout<<"========================================"<<endl;
        reg.getFechaNacimiento().mostrar();
        cout<<endl;

        if(reg.getEstado()){
            cout<<"Estado del socio = ACTIVO"<<endl;
        }
        else{
            cout<<"Estado del socio = INACTIVO"<<endl;
        }
        cout<<endl;
    }
    if(cantidad == 0){
        cout<<"No hay socios cargados"<<endl;
    }

}

void SociosManager::exportarACSV() {
    exportarSociosACSV(); 
}

void SociosManager::buscarSocios(){

    int numSocio;
    cout<<"Ingrese el numero de socio a buscar: ";
    cin>>numSocio;
    int pos = _archivo.buscarPorID(numSocio); //Buscamos el socio por su numero de socio y obtenemos la posicion del mismo en el archivo
    if(pos != -1){
        Socios reg = _archivo.leer(pos);
        cout<<"Numero de socio: "<<reg.getNumSocio()<<endl;
        cout<<"DNI del socio: "<<reg.getDni()<<endl;
        cout<<"Nombre del socio: "<<reg.getNombre()<<endl;
        cout<<"Apellido del socio: "<<reg.getApellido()<<endl;
        cout<<"Telefono del socio: "<<reg.getTelefono()<<endl;
        cout<<"Email del socio: "<<reg.getEmail()<<endl;
        cout<<"Fecha de nacimiento del socio:"<<endl;
        reg.getFechaNacimiento().mostrar();
        cout<<endl;

        if(reg.getEstado()){
            cout<<"Estado del socio = ACTIVO"<<endl;
        }
        else{
            cout<<"Estado del socio = INACTIVO"<<endl;
        }
    }
    else{
        cout<<"No se encontro el socio"<<endl;
    }
}

void SociosManager::modificarSocios(){
    int numSocio;
    int op;
    cout<<"Ingrese el Numero de socio que desea modificar:";
    cin>>numSocio;
    Socios reg;
    int pos = _archivo.buscarPorID(numSocio);
    if(pos != -1){
        reg = _archivo.leer(pos);
        cout<<endl;
        do{
        cout<<"Que desea modificar "<<endl;
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
            std::string nom;
            cout<<"Ingrese el nuevo nombre: ";
            getline(cin, nom);
            reg.setNombre(nom.c_str());
            break;
            }
            case 3:{
            std::string apellido;
            cout<<"ingrese el nuevo apellido: ";
            getline(cin, apellido);
            reg.setApellido(apellido.c_str());
            break;
            }
            case 4:{
            std::string telefono;
            cout<<"Ingrese el nuevo telefono: ";
            getline(cin, telefono);
            reg.setTelefono(telefono.c_str());
            break;
            }
            case 5:{
            std::string email;
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
                std::string nom, apellido, telefono, email;
                bool estado;
                Fecha fechaNacimiento;
                cout<<"Ingrese el nuevo DNI: ";
                cin>>dni;
                cin.ignore(); // Limpiar el buffer de entrada antes de usar getline
                cout<<"Ingrese el nuevo nombre: ";
                getline(cin, nom);
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

                bool valido = ValidarSocio(numSocio, dni, nom, apellido, telefono, email, fechaNacimiento, pos);
                if(!valido){
                    cout<<"Los datos ingresados no son validos"<<endl;
                    break;
                }

                reg.setDni(dni);
                reg.setNombre(nom.c_str());
                reg.setApellido(apellido.c_str());
                reg.setTelefono(telefono.c_str());
                reg.setEmail(email.c_str());
                reg.setEstado(estado);                
                reg.setFechaNacimiento(fechaNacimiento);
                break;
            }

            case 0:
            break;

            default:
            cout<<"Opcion invalida"<<endl;
        }
        if(op != 0 && !ValidarSocio(reg.getNumSocio(), reg.getDni(), reg.getNombre(), reg.getApellido(), reg.getTelefono(), reg.getEmail(), reg.getFechaNacimiento(), pos)){
            cout<<"No se guardaron los cambios, datos invalidos"<<endl;
            reg = _archivo.leer(pos); // Descartar los datos invalidos que quedaron en memoria
        }
        else if(_archivo.modificar(reg, pos)){
            cout<<"Socio modificado correctamente"<<endl;
        }
        else{
            cout<<"Error al modificar el socio"<<endl;

        };
    }while(op !=0);
    }
}


bool SociosManager::ValidarSocio(int numSocio, int dni, string nombre, string apellido, string telefono, string email, Fecha fechaNacimiento, int posExcluir)
    {
        if (numSocio <=0){
            cout<<"El numero de socio debe ser mayor a 0"<<endl;
            return false;
        }

        int posNumSocio = _archivo.buscarPorID(numSocio);
        if (posNumSocio != -1 && posNumSocio != posExcluir){
            cout<<"Ya existe un socio con ese numero de socio"<<endl;
            return false;
        }

        if (dni <= 0 || to_string(dni).length() != 8){
            cout<<"El DNI debe tener exactamente 8 digitos"<<endl;
            return false;
        }

        int posDni = _archivo.buscarPorDni(dni);
        if (posDni != -1 && posDni != posExcluir){
            cout<<"Ya existe un socio con ese DNI"<<endl;
            return false;
        }

        if (nombre.empty()){
            cout<<"El nombre no puede estar vacio"<<endl;
            return false;
        }

        if (apellido.empty()){
            cout<<"El apellido no puede estar vacio"<<endl;
            return false;
        }

        if (telefono.empty()){
            cout<<"El telefono no puede estar vacio"<<endl;
            return false;
        }

        if (email.empty()){
            cout<<"El email no puede estar vacio"<<endl;
            return false;
        }

        size_t posArroba = email.find('@');
        size_t posPunto = email.find('.', posArroba);

        if (posArroba == string::npos || posArroba == 0 || posArroba == email.length() - 1
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
        
        if (fechaNacimiento.getAnio() <=0){
            cout<<"La fecha de nacimiento debe ser mayor a 0"<<endl;
            return false;
        }

        return true;
    }