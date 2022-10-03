#include <iostream>
#include <stdio.h>

#include <SFML/Graphics.hpp>

int main()
{
    sf::Vector2f janela(800, 600);
    sf::Vector2f tamanho(50, 120);
    sf::Vector2f posicao(janela.x/2, janela.y/2 - tamanho.y/2);
    sf::Vector2f velocidade(0, 0);
    sf::Vector2f aceleracao(0, 0.0005);

    sf::RenderWindow window(sf::VideoMode(janela.x,janela.y), "Teste");
    sf::RectangleShape shape(tamanho);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::D)
                        velocidade.x = 0.1f;
                    if(event.key.code == sf::Keyboard::A)
                        velocidade.x = -0.1f;
                    if(event.key.code == sf::Keyboard::W && posicao.y >= janela.y - tamanho.y)
                        velocidade.y = -0.5;
                    break;
                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
                        velocidade.x = 0;
                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.x)
                default:
                    break;
            }
        }
        window.clear();

        posicao.x += velocidade.x;
        posicao.y += velocidade.y;

        velocidade.y += aceleracao.y;

        if(posicao.x < 0){
            posicao.x = 0;
            velocidade.x = 0;
        }
        else if(posicao.x > janela.x - tamanho.x){
            posicao.x = janela.x - tamanho.x;
            velocidade.x = 0;
        }
        if(posicao.y < 0){
            posicao.y = 0;
            velocidade.y = 0;
        }
        else if(posicao.y > janela.y - tamanho.y){
            posicao.y = janela.y - tamanho.y;
            velocidade.y = 0;
        }

        shape.setPosition(posicao.x,posicao.y);

        window.draw(shape);
        window.display();
    }

    return 0;
}
