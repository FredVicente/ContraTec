#include "Jogo.h"

void Jogo::Inicializar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");
    sf::View view1(sf::FloatRect(janela.x / 2, 0, janela.x, janela.y));

    Coord<float> tamanho(50,120);
    Jogador* jogador1 = new Jogador(Coord<float>(400,100), tamanho);
    fase1.player = jogador1;
    fase1.Executar();

    // Vari�veis de tempo.
    float dT = 0;
    float tAnt = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            jogador1->pControle.eventController(event);
        }

        // Gerenciador geral para update.
        dT += (clock() - tAnt) / CLOCKS_PER_SEC;
        if (dT > 40) {
            dT = 0;
            tAnt = clock();
            
            // Gerenciador Grafico
            window.clear();

            // Gerenciador Grafico
            view1.setCenter(jogador1->getPosicao().x + jogador1->getTamanho().x / 2, view1.getCenter().y);

            jogador1->mover();

            fase1.gC.Colisoes(*fase1.listaEntidadesEstaticas, *fase1.listaEntidadesMoveis);

            // Gerenciador Grafico
            int i = 0;
            Entidade* e;
            for (i = 0; i < fase1.listaEntidadesMoveis->getTamanho(); i++) {
                e = (*fase1.listaEntidadesMoveis)[i];
                window.draw(*e->getShape());
            }
            for (i = 0; i < fase1.listaEntidadesEstaticas->getTamanho(); i++) {
                e = (*fase1.listaEntidadesEstaticas)[i];
                window.draw(*e->getShape());
            }

            // Gerenciador Grafico
            window.setView(view1);
            window.display();
        }
    }

    return;
}