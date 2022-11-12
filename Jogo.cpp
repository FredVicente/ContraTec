#include "Jogo.h"

void Jogo::Inicializar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");
    sf::View view1(sf::FloatRect(janela.x / 2, 0, janela.x, janela.y));

    Coord<float> tamanho(50,120);
    Entidades::Jogador* jogador1 = new Entidades::Jogador(Coord<int>(0,0), Coord<float>(50,80), tamanho);
    fase1.player = jogador1;
    fase1.listaEntidades.lista.adicionar(jogador1);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            jogador1->pControle.eventController(event);
        }

        // Gerenciador Grafico
        window.clear();

        jogador1->Mover();

        // Gerenciador Grafico
        view1.setCenter(jogador1->getPosicao().x + jogador1->getTamanho().x / 2, view1.getCenter().y);

        fase1.gC.Colisoes(fase1.listaEntidades.lista);

        // Gerenciador Grafico
        int i = 0;
        Entidade* e;
        for (i = 0; i < fase1.listaEntidades.lista.getTamanho(); i++) {
            e = fase1.listaEntidades.lista[i];
            window.draw(*e->getShape());
        }

        // Gerenciador Grafico
        window.setView(view1);
        window.display();
    }

    return;
}