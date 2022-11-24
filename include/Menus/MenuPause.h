#pragma once

#include <Menu.h>

class MenuPause : public Menu{
public:
    MenuPause(vector<std::string> opMenu) : Menu(opMenu){};
    ~MenuPause() {};

    int menuEvent(int i){
        switch (i)
        {
        case 1:
            return entrarFaseAtual;
            break;
        case 2:
            return salvarJogo;
            break;
        case 3:
            return menu1;
            break;
        default:
            break;
        }
    };
};