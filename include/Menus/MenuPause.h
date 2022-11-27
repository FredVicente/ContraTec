#pragma once

#include <Menu.h>

class MenuPause : public Menu{
private:
    vector<int> acoes;
public:
    MenuPause() : Menu(){
        opcoes.push_back("Continuar");
        opcoes.push_back("Salvar");
        opcoes.push_back("Tela Inicial");

        acoes.push_back(entrarFaseAtual);
        acoes.push_back(salvarFase);
        acoes.push_back(menuPrincipal);

        Executar();
    };
    ~MenuPause() {};

    int menuEvent(int i){
        if(i < acoes.size())
            return acoes[i];
        else
            return -1;
    };
};