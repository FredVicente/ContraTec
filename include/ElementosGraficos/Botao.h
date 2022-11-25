#pragma once

#include "ElementoGrafico.h"

namespace ElementosGraficos {

    class Button : ElementoGrafico {
    private:
        Coord<int> posicao;
        sf::Text texto;
        sf::Font font;
    public:
        Button(Coord<int> pos = Coord<int>(0, 0), std::string info = "") : posicao(pos){
            Executar();
            texto.setString(info);

            body.setSize(sf::Vector2f(50, 70));
            body.setPosition(sf::Vector2f(50, 50));
            body.setFillColor(sf::Color::Yellow);
        };

        ~Button();

        void Executar(){
            if (!font.loadFromFile("../Fonts/PixelFont2.ttf")) {
                std::cout << "ERROR: Could not load font.";
                exit(1);
            }

            texto.setFont(font);
            texto.setPosition(50,50);
        };
    };
}