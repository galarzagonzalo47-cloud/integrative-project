#include "Menu.h"

Menu::Menu(){
    _clubesManager = ClubesManager();
    _sociosManager = SociosManager();
    _profesoresManager = ProfesoresManager();
    _disciplinasManager = DisciplinasManager();
    _sedesManager = SedesManager();
    _actividadesManager = ActividadesManager();
}

void Menu::mostrarMenu(){
    int opcion;
    do{
        cout<<"BIENVENIDO AL MENU DE CLUBES"<<endl;
        cout<<"Ingrese alguna de las siguientes secciones: "<<endl;
        cout<<"1. Clubes"<<endl;
        cout<<"2. Socios"<<endl;
        cout<<"3. Profesores"<<endl;
        cout<<"4. Disciplinas"<<endl;
        cout<<"5. Sedes"<<endl;
        cout<<"6. Actividades"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                _clubesManager.mostrarMenu();
                break;
                
            case 2:
                _sociosManager.mostrarMenu();
                break;

            case 3:
                _profesoresManager.mostrarMenu();
                break;

            case 4:
                _disciplinasManager.mostrarMenu();
                break;

            case 4:
                _sedesManager.mostrarMenu();
                break;

            case 4:
                _actividadesManager.mostrarMenu();
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
