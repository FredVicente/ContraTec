#include "Jogo.h"

Jogo::Jogo() : 
    jogador(Coord<float>(0,0), Coord<float>(50,120)),
    fase1()
{
    Inicializar();
}

void Jogo::Inicializar(){
    // Gerenciador grafico.
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");
    sf::View view1(sf::FloatRect(janela.x / 2, 0, janela.x, janela.y));

    fase1.player = &jogador;
    fase1.executar();

    // Vari�veis de tempo.
    float dT = 0;
    float tAnt = 0;

    Menu menu;
    sf::Font font;
    sf::Text vidas;
    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(24);
    vidas.setString("Vidas: 3");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            if(state == playing)
                jogador.pControle.eventController(event);
        }

        if(state == playing){
        // Gerenciador geral para update.
        dT += (clock() - tAnt) / CLOCKS_PER_SEC;
        if (dT > 40) {
            dT = 0;
            tAnt = clock();

            // Gerenciador Grafico
            window.clear();

            jogador.mover();

            fase1.gC.colisoes(fase1.listaEntidadesEstaticas, fase1.listaEntidadesMoveis);

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

            //
            vidas.setPosition(view1.getCenter() - sf::Vector2f(janela.x / 2, janela.y / 2));
            window.draw(vidas);
            // Gerenciador Grafico
            view1.setCenter(jogador.getPosicao().x + jogador.getTamanho().x / 2, view1.getCenter().y);

            window.setView(view1);
            window.display();
        }
        else {
            window.clear();
            menu.executar(&window);
            window.setView(view1);
            window.display();
        }
        }
    }

    return;
}