#include "Principal.h"

void Principal::Inicializar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");

    Coord<float> tamanho(50,120);
    Entidades::Jogador* jogador1 = new Entidades::Jogador(Coord<int>(0,0), Coord<float>(30,50), tamanho);
    fase1.player = jogador1;
    fase1.lista.push_back(jogador1);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:

                if (event.key.code == sf::Keyboard::D)
                    jogador1->pControle.notifyPressed("D");
                else if (event.key.code == sf::Keyboard::A)
                    jogador1->pControle.notifyPressed("A");
                else if (event.key.code == sf::Keyboard::W && jogador1->pulo) 
                    jogador1->pControle.notifyPressed("W");
                else if (event.key.code == sf::Keyboard::Num1)
                    jogador1->pControle.notifyPressed("1");

            case sf::Event::KeyReleased:

                if (event.key.code == sf::Keyboard::D)
                    jogador1->pControle.notifyReleased("D");
                else if (event.key.code == sf::Keyboard::A)
                    jogador1->pControle.notifyReleased("A");
                else if (event.key.code == sf::Keyboard::W && jogador1->pulo) 
                    jogador1->pControle.notifyReleased("W");
                else if (event.key.code == sf::Keyboard::Num1)
                    jogador1->pControle.notifyReleased("1");

            default:
                break;
            }
        }
        window.clear();

        jogador1->Mover();

        fase1.gC.Colisoes(fase1.lista);

        std::list<Entidade*>::iterator iterador = fase1.lista.begin();
        while (iterador != fase1.lista.end()) {
            Entidade* entidade = *iterador;
            window.draw(*entidade->getShape());
            iterador++;
        }

        window.display();
    }

    return;
}