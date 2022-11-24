#include "Jogo.h"

Jogo::Jogo() :
    gGrafico(gGrafico->getInstancia())
{
    fase1 = nullptr;
    fase2 = nullptr;
    pFaseAtual = nullptr;

    vector<std::string> opMenu;
    opMenu.push_back("Jogar");
    opMenu.push_back("Continuar");
    opMenu.push_back("Sair");
    startMenu = new Menu(opMenu);
    startMenu->Executar();

    // Sistema pra salvar
    vector<std::string> opPause;
    opPause.push_back("Continuar");
    opPause.push_back("Salvar");
    opPause.push_back("Menu");
    pauseMenu = new Menu(opPause);
    pauseMenu->Executar();

    Inicializar();
}

void Jogo::Inicializar(){
    sf::RenderWindow* window = gGrafico->getJanela();
    window->setView(*(gGrafico->getView()));
    // Vari�veis de tempo.
    float dt = 0;
    float tAnt = 0;

    while (gGrafico->janelaAberta()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                gGrafico->fecharJanela();

            if (state == playing) {
                jogador->pControle.eventController(event);
                if (event.KeyPressed && event.key.code == sf::Keyboard::P)
                    state = pause;
            }
            else {
                if (state == menu) {
                    switch (startMenu->Alterar(event)) {
                    case 1:
                        faseAtual = 0;
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
        }

        gGrafico->clear();
        if (state == playing) {
            if (Fase::faseAtual != faseAtual)
                setFase(Fase::faseAtual);

            dt += (clock() - tAnt) / CLOCKS_PER_SEC;

            if (dt > 20) {
                pFaseAtual->Atualizar(dt);
                tAnt = dt;
                dt = 0;
            }

            if (jogador->getVidas() <= 0 || jogador->getPosicao().y > 1000)
                state = menu;
        }
        else {
            switch (state) {
            case menu:
                startMenu->Atualizar();
                window->display();
                break;
            case pause:
                pauseMenu->Atualizar();
                window->display();
                break;
            }
        }
    }

    return;
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
}