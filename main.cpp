#include <iostream>
#include "SociosManager.h"

int main(){
    SociosManager manager;
    int opcion;
    do{
        cout<<"BIENVENIDO AL MENU DE GESTION DE FUTBOL"<<endl;
        cout<<"Seleccione algunas de las siguientes opciones: "<<endl;
        cout<<"1. Cargar Socios"<<endl; 
        cout<<"2. Listar Socios"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
            manager.cargarSocios();
            system("pause");
            system("cls");
            break;
            case 2:
            manager.listarSocios();
            system("pause");
            system("cls");
            break;

            default:
            if(opcion != 0){
                cout<<"Opcion invalida, intente nuevamente"<<endl;
                system("pause");
            }
        }
    }while(opcion != 0);
    return 0;
}

/*
Claude quiere que mandemos esto: 
INTEGRANTES: Valentin Nigro, Agustin Bautista Rojas Falcucci, Martin Fano, Gonzalo Galarza
Tipo de proyecto: Gestión
Tema: Actividades de un club

Archivos a utilizar:

Socio.dat
NumSocio : int
Dni : int
Nombre : char[30]
Apellido : char[30]
Telefono : char[20]
Email : char[40]
FechaNacimiento : Fecha
Estado : bool
//HECHO

Profesor.dat
NumProfesor : int
Dni : int
Nombre : char[30]
Apellido : char[30]
Telefono : char[20]
Email : char[40]
FechaNacimiento : Fecha
Estado : bool

Disciplina.dat
NumDisciplina : int
Nombre : char[40]
Descripcion : char[80]
Estado : bool

Sede.dat
NumSede : int
Nombre : char[40]
Direccion : char[60]
Telefono : char[20]
Estado : bool

Actividad.dat
NumActividad : int
Nombre : char[40]
NumProfesor : int
NumDisciplina : int
NumSede : int
FechaInicio : Fecha
Arancel : float
CupoMaximo : int
Estado : bool

Inscripcion.dat
NumInscripcion : int
NumActividad : int
NumSocio : int
FechaInscripcion : Fecha
Estado : bool

Cuota.dat
NumCuota : int
NumInscripcion : int
MesPeriodo : int
AnioPeriodo : int
Importe : float
FechaVencimiento : Fecha
Pagada : bool
Estado : bool

Pago.dat
NumPago : int
NumCuota : int
FechaPago : Fecha
ImportePagado : float
MedioPago : char[15]
Estado : bool

Asistencia.dat
NumAsistencia : int
NumInscripcion : int
FechaAsistencia : Fecha
Presente : bool
Estado : bool
*/