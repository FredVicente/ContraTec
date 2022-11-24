#pragma once

#include <Menu.h>

class MenuPrincipal : public Menu{
public:
    MenuPrincipal(vector<std::string> opMenu) : Menu(opMenu){};
    ~MenuPrincipal() {};

    int menuEvent(int i){
        switch (i)
        {
        case 1:
            return menu2;
            break;
        case 2:
            return salvarJogo;
            break;
        case 3:
            return sairJogo;
            break;
        default:
            break;
        }
    };
};