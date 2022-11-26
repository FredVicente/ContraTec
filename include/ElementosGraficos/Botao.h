#pragma once

#include "ElementoGrafico.h"

namespace ElementosGraficos {

    class Botao : public ElementoGrafico {
    private:
        Coord<int> posicao;
        Coord<int> tamanho;
        sf::Text* texto;
    public:
        Botao(sf::Font font, Coord<int> pos = Coord<int>(0, 0), std::string info = "") : 
        posicao(pos),
        tamanho(Coord<int>(100, 50)),
        ElementoGrafico()
        {
            texto = new sf::Text();
            texto->setFont(font);
            texto->setString(info);
            texto->setPosition(sf::Vector2f(pos.x, pos.y));
            
            body.setSize(sf::Vector2f(tamanho.x, tamanho.y));
            body.setPosition(sf::Vector2f(pos.x, pos.y));
            body.setFillColor(sf::Color::Yellow);
        };

        ~Botao(){};

        Coord<int> getPosicao(){ return posicao; };
        Coord<int> getTamanho(){ return tamanho; };

        void imprimir(){
            gGrafico->renderizar(&body);
            gGrafico->renderizar(texto);
        };

        void Executar(){};
    };
}