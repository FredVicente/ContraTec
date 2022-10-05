#include <stdio.h>
#include <iostream>
#include "Principal.h"
#include <SFML/Graphics.hpp>

void Principal::Executar(){
    sf::Vector2f janela(800, 600);
    sf::Vector2f tamanho(50, 120);
    sf::Vector2f posicao(janela.x / 2, janela.y / 2 - tamanho.y / 2);
    sf::Vector2f velocidade(0, 0);
    sf::Vector2f aceleracao(0, 0.0005);

    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");
    sf::RectangleShape shape(tamanho);

    Plataforma plataforma(40, 500, 200, 50);

    bool pulo = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::D)
                    velocidade.x = 0.1f;
                if (event.key.code == sf::Keyboard::A)
                    velocidade.x = -0.1f;
                if (event.key.code == sf::Keyboard::W && pulo == true) {
                    velocidade.y = -0.5;
                    pulo = false;
                }
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
                    velocidade.x = 0;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.x)
            default:
                break;
            }
        }
        window.clear();

        posicao.x += velocidade.x;
        posicao.y += velocidade.y;

        velocidade.y += aceleracao.y;

        // Colisao
        if (posicao.x + tamanho.x > plataforma.posicao.x && posicao.x < plataforma.posicao.x + plataforma.tamanho.x) {
            if (posicao.y + tamanho.y > plataforma.posicao.y && posicao.y + tamanho.y < plataforma.posicao.y + plataforma.tamanho.y / 2) {
                posicao.y = plataforma.posicao.y - tamanho.y;
                velocidade.y = 0;
                pulo = true;
            }
            else if (posicao.y < plataforma.posicao.y + plataforma.tamanho.y && posicao.y > plataforma.posicao.y + plataforma.tamanho.y / 2) {
                posicao.y = plataforma.posicao.y + plataforma.tamanho.y;
                velocidade.y = 0;
            }
        }

        if (posicao.y < 0) {
            posicao.y = 0;
            velocidade.y = 0;
        }

        if (posicao.y > janela.y - tamanho.y) {
            posicao.y = janela.y - tamanho.y;
            velocidade.y = 0;
            pulo = true;
        }

        shape.setPosition(posicao.x, posicao.y);

        window.draw(shape);

        window.draw(plataforma.getShape());

        window.display();
    }

    return;
}
