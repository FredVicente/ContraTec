#pragma once

#include <Menu.h>

class MenuPrincipal : public Menu{
private:
    vector<int> acoes;
public:
    MenuPrincipal() : Menu(){
        opcoes.push_back("Jogar");
        opcoes.push_back("Continuar");
        opcoes.push_back("Ranking");
        opcoes.push_back("Sair");

        acoes.push_back(menuEscolherFase);
        acoes.push_back(carregarFase);
        acoes.push_back(menuRanking);
        acoes.push_back(sairJogo);

        Executar();
    };
    ~MenuPrincipal() {};

    int menuEvent(int i){
        if(i < acoes.size())
            return acoes[i];
        else
            return -1;
    };
};