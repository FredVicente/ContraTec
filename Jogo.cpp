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

<<<<<<< Updated upstream
            jogador1->pControle.eventController(event);
=======
            if (state == playing) {
                jogador->pControle.eventController(event);
                if (event.KeyPressed && event.key.code == sf::Keyboard::P)
                    state = pause;
            }
            else {
                if (state == menu) {
                    switch (startMenu->Alterar(event)) {
                    case 1:
                        Fase::faseAtual = 1;
                        setFase(1);
                        state = playing;
                        break;
                    case 2:
                        state = playing;
                        Carregar();
                        break;
                    case 3:
                        exit(0);
                        break;
                    default:
                        break;
                    }
                }
                else if (state == pause) {
                    switch (pauseMenu->Alterar(event)) {
                    case 1:
                        state = playing;
                        break;
                    case 2:
                        Salvar();
                        break;
                    case 3:
                        state = menu;
                        break;
                    default:
                        break;
                    }
                }
            }
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
            jogador1->mover();
=======
            if (dt > 40) {
                pFaseAtual->Atualizar(dt);
                tAnt = dt;
                dt = 0;
            }
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
=======
}

void Jogo::setFase(int fase, string path) {
    if (pFaseAtual)
        delete(pFaseAtual);

    faseAtual = fase;

    jogador = new Jogador(Coord<float>(50, 90));

    switch (faseAtual) {
    case(1):
        fase1 = new Fase1(jogador, path);
        pFaseAtual = fase1;
        break;
    case(2):
        fase2 = new Fase2(jogador, path);
        pFaseAtual = fase2;
        break;
    default:
        break;
    }
    pFaseAtual->Executar();
}

void Jogo::Salvar() {
    ofstream file;
    file.open("save.txt");
    int i, tam = pFaseAtual->listaEntidadesMoveis->getTamanho();

    file << to_string(faseAtual) + "\n";

    for (i = 0; i < tam; i++) {
        Entidade* e = (*(pFaseAtual->listaEntidadesMoveis))[i];
        char estado = '0';
        if (e->getEstado())
            estado = '1';
        if(e->getID() != projetil)
            file << to_string(e->getID()) + estado + ": " + to_string((int)e->getPosicao().x) + "-" + to_string((int)e->getPosicao().y) + "_" + "\n";
    }
    //file << to_string(jogador->pontos);
    file.close();
}

void Jogo::Carregar() {
    ifstream file;
    file.open("save.txt");
    if(!file)
        return;

    string valor;
    file >> valor;
    Fase::faseAtual = stoi(valor);

    // Sem refencira para o jogador!
    //file >> jogador->pontos;
    file.close();

    setFase(Fase::faseAtual, "save.txt");
>>>>>>> Stashed changes
}