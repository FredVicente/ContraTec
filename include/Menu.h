#pragma once
#include <vector>
#include "Ente.h"
#include "Math/Coord.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace Math;

enum MenuReturn {
	menu1 = 0,
    menu2,
    menu3,
    entrarFase1,
    entrarFase2,
    menuPausa,
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

    void Executar();

    void Atualizar();

    int Alterar(sf::Event e);

    virtual int menuEvent(int i) = 0;
};

