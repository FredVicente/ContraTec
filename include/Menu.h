#pragma once
#include <vector>
#include "Ente.h"
#include "Math/Coord.h"
#include "SFML/Graphics.hpp";

using namespace std;
using namespace Math;

class Menu : public Ente{
private:
    int selected;
    sf::Font font;

    vector<const char*> opcoes;
    vector<sf::Vector2f> posicoes;
    vector<sf::Text> textos;
public:
    Menu();
    ~Menu() {};

    void executar() {};

    void executar(sf::RenderWindow* window);

    int alterar(sf::Event e);
};

