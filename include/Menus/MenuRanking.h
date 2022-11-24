#pragma once

#include <Menu.h>

class MenuRanking : public Menu{
public:
    MenuRanking(vector<std::string> opMenu) : Menu(opMenu){
    };
    ~MenuRanking() {};

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