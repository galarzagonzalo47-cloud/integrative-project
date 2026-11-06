#pragma once
#include <iostream>
#include "../Socios/SociosManager/SociosManager.h"
#include "../Profesor/ProfesorManager/ProfesorManager.h"
class Menu{
    private:
    SociosManager _sociosManager;
    ProfesorManager _profesorManager;

    public:
    Menu();
    void mostrarMenu();
};
                            