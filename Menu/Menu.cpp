#include "Menu.h"

Menu::Menu(){
    _sociosManager = SociosManager();
    _profesorManager = ProfesorManager();
    _disciplinaManager = DisciplinaManager();
    _sedeManager = SedeManager();
}

void Menu::mostrarMenu(){
    int opcion;
    do{
        cout<<"BIENVENIDO AL MENU DE GESTION DE FUTBOL"<<endl;
        cout<<"Ingrese alguna de las siguientes secciones: "<<endl;
        cout<<"1. Gestion de Socios"<<endl;
        cout<<"2. Gestion de Profesores"<<endl;
        cout<<"3. Gestion de Disciplinas"<<endl;
        cout<<"4. Gestion de Sedes"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                _sociosManager.mostrarMenu();
                break;
            case 2:
                _profesorManager.mostrarMenu();
                break;
            case 3:
                _disciplinaManager.mostrarMenu();
                break;
            case 4:
                _sedeManager.mostrarMenu();
                break;
            default:
                if(opcion != 0){
                    cout<<"Opcion invalida, intente nuevamente"<<endl;
                    system("pause");
                }
        }
    }while(opcion != 0);
    return;
}
