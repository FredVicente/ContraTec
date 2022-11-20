#include "Jogo.h"

Jogo::Jogo()
{
    Inicializar();
}

void Jogo::Inicializar(){
    // Gerenciador grafico.
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");
    sf::View view(sf::FloatRect(0, 0, janela.x, janela.y));

    fase1 = new Fase1();
    pFaseAtual = fase1;
    pFaseAtual->executar();
    jogador = fase1->player;
    fase2 = nullptr;

    // Vari�veis de tempo.
    float dT = 0;
    float tAnt = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            if (state == playing) {
                jogador->pControle.eventController(event);
                if (event.KeyPressed && event.key.code == sf::Keyboard::P)
                    state = pause;
            }
            else {
                switch (menu.alterar(event)) {
                    case 1:
                        state = playing;
                        break;
                    case 3:
                        exit(0);
                        break;
                    default:
                        break;
                }
            }
        }

        if (state == playing) {
            // Gerenciador geral para update.
            dT += (clock() - tAnt) / CLOCKS_PER_SEC;
            if (dT > 100) {
                dT = 0;
                tAnt = clock();

                if (Fase::faseAtual != faseAtual) {
                    pFaseAtual->clear();
                    faseAtual = Fase::faseAtual;

                    switch (faseAtual) {
                    case(0):
                        fase1 = new Fase1();
                        pFaseAtual = fase1;
                        break;
                    case(1):
                        fase2 = new Fase2();
                        pFaseAtual = fase2;
                        break;
                    default:
                        break;
                    }
                    pFaseAtual->executar();
                    jogador = pFaseAtual->player;
                }
                
                pFaseAtual->atualizar(&view, &window);
            }
        }
        else {
            window.clear();
            menu.executar(&window);
            view.setCenter(janela.x/2, janela.y/2);
            window.setView(view);
            window.display();
        }
    }

    return;
}