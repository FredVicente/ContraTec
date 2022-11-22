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

    vector<string> opcoes;
    vector<sf::Vector2f> posicoes;
    vector<sf::Text> textos;
public:
    Menu(vector<std::string> opMenu);
    ~Menu() {};

    void Executar();

    void Atualizar(sf::RenderWindow* window);

    int Alterar(sf::Event e);
};

