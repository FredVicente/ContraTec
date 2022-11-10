#include "Principal.h"

void Principal::Inicializar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");
    sf::View view1(sf::FloatRect(janela.x / 2, janela.y / 2, janela.x, janela.y));

    Coord<float> tamanho(50,120);
    Entidades::Jogador* jogador1 = new Entidades::Jogador(Coord<int>(0,0), Coord<float>(50,80), tamanho);
    fase1.player = jogador1;
    fase1.lista.push_back(jogador1);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            jogador1->pControle.eventController(event);
        }

        window.clear();

        jogador1->Mover();
        view1.setCenter(jogador1->getPosicao().x, jogador1->getPosicao().y);

        fase1.gC.Colisoes(fase1.lista);

        std::list<Entidade*>::iterator iterador = fase1.lista.begin();
        while (iterador != fase1.lista.end()) {
            Entidade* entidade = *iterador;
            window.draw(*entidade->getShape());
            iterador++;
        }

        window.setView(view1);
        window.display();
    }

    return;
}