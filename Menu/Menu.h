#pragma once
#include <iostream>
#include "../Clubes/ClubesManager/ClubesManager.h"
#include "../Socios/SociosManager/SociosManager.h"
#include "../Profesor/ProfesoresManager/ProfesoresManager.h"
#include "../Disciplina/DisciplinasManager/DisciplinasManager.h"
#include "../Sedes/SedesManager/SedesManager.h"
#include "../Actividades/ActividadesManager/ActividadesManager.h"

class Menu{
    private:
    ClubesManager _clubesManager;
    SociosManager _sociosManager;
    ProfesoresManager _profesoresManager;
    DisciplinasManager _disciplinasManager;
    SedesManager _sedesManager;
    ActividadesManager _actividadesManager;

    public:
    Menu();
    void mostrarMenu();
};
                            