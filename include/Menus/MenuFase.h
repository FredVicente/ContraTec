#pragma once

#include <Menu.h>

class MenuFase : public Menu{
public:
    MenuFase(vector<std::string> opMenu) : Menu(opMenu){};
    ~MenuFase() {};

    int menuEvent(int i){
        switch (i)
        {
        case 1:
            return entrarFase1;
            break;
        case 2:
            return entrarFase2;
            break;
        case 3:
            return menu1;
            break;
        default:
            break;
        }
    };
};