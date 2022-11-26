#pragma once

#include "ElementoGrafico.h"

namespace ElementosGraficos {

    class Input : public ElementoGrafico {
    protected:
        Coord<int> posicao;
        sf::Text* texto;
        std::string textInput;
    public:
        Input(sf::Font font, Coord<int> pos = Coord<int>(0, 0)) :
        posicao(pos),
        ElementoGrafico()
        {
            body.setSize(sf::Vector2f(200, 80));
            body.setPosition(sf::Vector2f(pos.x, pos.y));
            body.setFillColor(sf::Color::Transparent);
            body.setOutlineThickness(5);
            body.setOutlineColor(sf::Color::White);

            texto = new sf::Text();
            texto->setFont(font);
            texto->setString("1");
            texto->setPosition(sf::Vector2f(posicao.x, posicao.y));
            texto->setCharacterSize(28);

            textInput = "";
        };

        ~Input(){};

        void addText(sf::Uint32 t){
            textInput += t;
            texto->setString(textInput);
            texto->setCharacterSize(24);
        };

        void imprimir(){
            gGrafico->renderizar(&body);
            gGrafico->renderizar(texto);
        };

        void Executar(){};
    };
}