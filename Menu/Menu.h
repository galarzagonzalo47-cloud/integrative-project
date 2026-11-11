#pragma once
#include <iostream>
#include "../Socios/SociosManager/SociosManager.h"
#include "../Profesor/ProfesorManager/ProfesorManager.h"
#include "../Disciplina/DisciplinaManager/DisciplinaManager.h"
#include "../Sedes/SedesManager/SedesManager.h"
class Menu{
    private:
    SociosManager _sociosManager;
    ProfesorManager _profesorManager;
    DisciplinaManager _disciplinaManager;
    SedesManager _sedesManager;

    public:
    Menu();
    void mostrarMenu();
};
                            