#pragma once
#include <vector>
#include "Ente.h"
#include "Math/Coord.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace Math;

enum MenuReturn {
	menuPrincipal = 0,
    menuEscolherFase,
    menuPausa,
    menuNomeDoJogador,
    entrarFase1,
    entrarFase2,
    salvarJogo,
    sairJogo,
    entrarFaseAtual
};


class Menu : public Ente{
protected:
    int selected;
    sf::Font font;

    vector<string> opcoes;
    vector<sf::Vector2f> posicoes;
    vector<sf::Text> textos;
public:
    Menu(vector<std::string> opMenu);
    Menu(){};
    ~Menu() {};

    virtual void Executar();

    virtual void Atualizar();

    virtual int Alterar(sf::Event e);

    virtual int menuEvent(int i) { return -1; };
};

