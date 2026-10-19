#include "SociosManager.h"

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
    }
    if(cantidad == 0){
        cout<<"No hay socios cargados"<<endl;
    }

}
/*
    int _numSocio;
    int _dni;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email [40];
    bool _estado;
*/