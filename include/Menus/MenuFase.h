#pragma once

#include <Menu.h>

class MenuFase : public Menu{
private:
    vector<int> acoes;
public:
    MenuFase() : Menu(){
        opcoes.push_back("Fase 1");
        opcoes.push_back("Fase 2");
        opcoes.push_back("Voltar");

        acoes.push_back(entrarFase1);
        acoes.push_back(entrarFase2);
        acoes.push_back(menu1);

        Executar();
    };
    ~MenuFase() {};

    int menuEvent(int i){
        if(i < acoes.size())
            return acoes[i];
        else
            return -1;
    };
};