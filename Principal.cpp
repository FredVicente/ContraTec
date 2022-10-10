#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Principal.h"

void Principal::Executar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");

    sf::Vector2f t(50, 120);

    Personagem* personagem = new Personagem(30, 100, t.x, t.y);
    Plataforma* plataforma = new Plataforma(200, 450, 120, 40);
    Plataforma* plataforma2 = new Plataforma(350, 300, 200, 40);
    Plataforma* chao = new Plataforma(0, 550, 800, 100);

    std::list<Objeto*> objetos;
    std::list<Objeto*>::iterator iterador;

    objetos.push_back(plataforma);
    objetos.push_back(plataforma2);
    objetos.push_back(chao);
    
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
                    personagem->velocidade.x = 0.1f;
                if (event.key.code == sf::Keyboard::A)
                    personagem->velocidade.x = -0.1f;
                if (event.key.code == sf::Keyboard::W && personagem->pulo == true) {
                    personagem->velocidade.y = -0.7;
                    personagem->pulo = false;
                }
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::D && personagem->velocidade.x == 0.1f ||
                    event.key.code == sf::Keyboard::A && personagem->velocidade.x == -0.1f)
                        personagem->velocidade.x = 0;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.x)
            default:
                break;
            }
        }
        window.clear();

        personagem->Mover();

        if (personagem->posicao.y < 0) {
            personagem->posicao.y = 0;
            personagem->velocidade.y = 0;
        }

        if (personagem->posicao.y > janela.y - personagem->tamanho.y) {
            personagem->posicao.y = janela.y - personagem->tamanho.y;
            personagem->velocidade.y = 0;
            personagem->pulo = true;
        }

        iterador = objetos.begin();
        while (iterador != objetos.end()) {
            Objeto* obj = NULL;
            obj = *iterador;

            if (personagem->posicao.x + personagem->tamanho.x > obj->posicao.x && personagem->posicao.x < obj->posicao.x + obj->tamanho.x) {
                if (personagem->posicao.y + personagem->tamanho.y > obj->posicao.y && personagem->posicao.y + personagem->tamanho.y < obj->posicao.y + obj->tamanho.y / 2) {
                    personagem->posicao.y = obj->posicao.y - personagem->tamanho.y;
                    personagem->velocidade.y = 0;
                    personagem->pulo = true;
                }
                else if (personagem->posicao.y < obj->posicao.y + obj->tamanho.y && personagem->posicao.y > obj->posicao.y + obj->tamanho.y / 2) {
                    personagem->posicao.y = obj->posicao.y + obj->tamanho.y;
                    personagem->velocidade.y = 0;
                }
            }
            if (personagem->posicao.y + personagem->tamanho.y > obj->posicao.y && personagem->posicao.y < obj->posicao.y + obj->tamanho.y) {
                if (personagem->posicao.x + personagem->tamanho.x > obj->posicao.x && personagem->posicao.x + personagem->tamanho.x < obj->posicao.x + obj->tamanho.x / 2) {
                    personagem->posicao.x = obj->posicao.x - personagem->tamanho.x;
                    personagem->velocidade.x = 0;
                }
                else if (personagem->posicao.x < obj->posicao.x + obj->tamanho.x && personagem->posicao.x > obj->posicao.x + obj->tamanho.x / 2) {
                    personagem->posicao.x = obj->posicao.x + obj->tamanho.x;
                    personagem->velocidade.x = 0;
                }
            }
            window.draw(*obj->shape);
            iterador++;
        }
        personagem->setPosicao(personagem->posicao.x, personagem->posicao.y);

        window.draw(*personagem->shape);

        window.display();
    }

    return;
}
