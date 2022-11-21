#include "Jogo.h"

void Jogo::Inicializar(){

    pGrafico = pGrafico->getInstancia();
    Jogador* jogador1 = new Jogador(Coord<float>(400,100), Coord<float>(50,120));
    jogador1->setFase(&fase1);
    fase1.player = jogador1;
    fase1.Executar();

    // Vari�veis de tempo.
    float dT = 0;
    float tAnt = 0;

    // Menu
    sf::Font font;
    sf::Text vidas;
    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(24);
    vidas.setString("Vidas: 3");

    while (pGrafico->janelaAberta()) {
        sf::Event event;
        while (pGrafico->getJanela()->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                pGrafico->fecharJanela();

            if (state == playing) {
                if (event.KeyPressed && event.key.code == sf::Keyboard::P)
                    state = pause;
                else
                    jogador1->pControle.eventController(event);
            }
            else if(menu.alterar(event) == 1)
                state = playing;
        }

        // Gerenciador geral para update.
        if(state == playing){
            dT += (clock() - tAnt) / CLOCKS_PER_SEC;
            if (dT > 40) {
                int i = 0;
                Entidade* e;
                for (i = 0; i < fase1.listaEntidadesMoveis->getTamanho(); i++) {
                    e = (*fase1.listaEntidadesMoveis)[i];
                    if(e->getEstado())
                        e->Atualizar(dT);
                }

                dT = 0;
                tAnt = clock();
                
                // Gerenciador Grafico
                pGrafico->clear();

                // Gerenciador Grafico
                pGrafico->centralizarView(jogador1->getPosicao().x + jogador1->getTamanho().x / 2);

                fase1.gC.Colisoes(*fase1.listaEntidadesEstaticas, *fase1.listaEntidadesMoveis);

                // Gerenciador Grafico
                for (i = 0; i < fase1.listaEntidadesMoveis->getTamanho(); i++) {
                    e = (*fase1.listaEntidadesMoveis)[i];
                    if(e->getEstado())
                        pGrafico->renderizar(e->getShape());
                }
                for (i = 0; i < fase1.listaEntidadesEstaticas->getTamanho(); i++) {
                    e = (*fase1.listaEntidadesEstaticas)[i];
                    pGrafico->renderizar(e->getShape());
                }

                // Gerenciador Grafico
                pGrafico->display();
            }
        }
        else{
            pGrafico->clear();
            menu.Executar(pGrafico->getJanela());
            pGrafico->centralizarView();
            pGrafico->display();
        }
    }

    return;
}