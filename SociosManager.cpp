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
    cout<<"Ingrese el numero de socios: ";
    cin>>numSocio;
    reg.setNumSocio(numSocio);
    cout<<endl;
    cout<<"Ingrese el DNI del socio: ";
    cin>>dni;
    reg.setDni(dni);
    cout<<endl;
    cin.ignore(); // Limpiar el buffer de entrada antes de usar getline
    cout<<"Ingrese el nombre del socio: ";
    getline(cin, nombre);
    reg.setNombre(nombre.c_str());
    cout<<endl;
    cout<<"Ingrese el apellido del socio: ";
    getline(cin, apellido);
    reg.setApellido(apellido.c_str());
    cout<<endl;
    cout<<"Ingrese un telefono del socio: ";
    getline(cin, telefono);
    reg.setTelefono(telefono.c_str());
    cout<<endl;
    cout<<"Ingrese un email del socio: ";
    getline(cin, email);
    reg.setEmail(email.c_str());
    cout<<endl;
    cout<<"Ingrese la fecha de nacimiento del socio: "<<endl;
    Fecha fechaNacimiento;
    fechaNacimiento.cargar();
    reg.setFechaNacimiento(fechaNacimiento);
    cout<<endl;
    reg.setEstado(true);

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
        cout<<"Numero de socio: "<<reg.getNumSocio()<<endl;
        cout<<"DNI del socio: "<<reg.getDni()<<endl;
        cout<<"Nombre del socio: "<<reg.getNombre()<<endl;
        cout<<"Apellido del socio: "<<reg.getApellido()<<endl;
        cout<<"Telefono del socio: "<<reg.getTelefono()<<endl;
        cout<<"Email del socio: "<<reg.getEmail()<<endl;
        cout<<"Fecha de nacimiento del socio:";
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
        cout<<"Fecha de nacimiento del socio:";
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
                reg.setDni(dni);
                reg.setNombre(nom.c_str());
                reg.setApellido(apellido.c_str());
                reg.setTelefono(telefono.c_str());
                reg.setEmail(email.c_str());
                reg.setEstado(estado);
                Fecha fechaNacimiento;
                cout<<"Ingrese la nueva fecha de nacimiento: "<<endl;
                fechaNacimiento.cargar();
                reg.setFechaNacimiento(fechaNacimiento);
                break;
            }
            default:
            cout<<"Opcion invalida"<<endl;
        }
        if(_archivo.modificar(reg, pos)){
            cout<<"Socio modificado correctamente"<<endl;
        }
        else{
            cout<<"Error al modificar el socio"<<endl;

        };
    }while(op !=0);
    }
}