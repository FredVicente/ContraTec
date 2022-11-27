#include "Jogo.h"

Jogo::Jogo() :
    gGrafico(gGrafico->getInstancia()),
    pMenuAtual(nullptr)
{
    fase1 = nullptr;
    fase2 = nullptr;
    pFaseAtual = nullptr;

    // Menus
    pMenuPrincipal = new MenuPrincipal();
    pMenuFase = new MenuFase();
    pMenuPause = new MenuPause();
    pMenuNomeJogador = new MenuNomeJogador();
    pMenuRanking = new MenuRanking();

    Inicializar();
}

void Jogo::Inicializar(){
    pMenuAtual = pMenuPrincipal;
    
    sf::RenderWindow* window = gGrafico->getJanela();
    window->setView(*(gGrafico->getView()));

    float dt = 0;
    float tAnt = 0;

    while (gGrafico->janelaAberta()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                gGrafico->fecharJanela();

            if (state == playing) {
                jogador->pControle.eventController(event);
                if (event.KeyPressed && event.key.code == sf::Keyboard::P){
                    state = pause;
                    pMenuAtual = pMenuPause;
                }
            }
            else {
                switch (pMenuAtual->Alterar(event)) {
                    case menuPrincipal:
                        pMenuAtual = pMenuPrincipal;
                        break;
                    case menuEscolherFase:
                        pMenuAtual = pMenuFase;
                        break;
                    case menuNomeDoJogador:
                        pMenuAtual = pMenuNomeJogador;
                        break;
                    case menuRanking:
                        CarregarRanking();
                        pMenuAtual = pMenuRanking;
                        break;
                    case entrarFase1:
                        state = playing;
                        setFase(1);
                        break;
                    case entrarFase2:
                        state = playing;
                        setFase(2);
                        break;
                    case entrarFaseAtual:
                        state = playing;
                        break;
                    case salvarFase:
                        SalvarFase();
                        pMenuAtual = pMenuPrincipal;
                        break;
                    case salvarRanking:
                        SalvarRanking();
                        CarregarRanking();
                        pMenuAtual = pMenuRanking;
                        break;
                    case sairJogo:
                        exit(0);
                        break;
                    default:
                        break;
                }
            }
        }
        gGrafico->clear();
        if (state == playing) {
            if (Fase::faseAtual != faseAtual)
                setFase(Fase::faseAtual);

            float c = clock();
            dt += (c - tAnt) / CLOCKS_PER_SEC;

            if (dt > 5) {
                pFaseAtual->Atualizar(dt);
                tAnt = c;
                dt = 0;
            }

            if (!jogador->estaAtivo() || jogador->getPosicao().y > 1000) {
                state = menu;
                pMenuAtual = pMenuNomeJogador;
                faseAtual = 0;
            }
        }
        else {
            pMenuAtual->Atualizar();
            window->display();
        }
    }
}

void Jogo::setFase(int fase, string path) {
    if (pFaseAtual)
        delete(pFaseAtual);

    Fase::faseAtual = fase;
    faseAtual = fase;

    int pontos = 0;
    if (jogador)
        pontos = jogador->pontos;

    jogador = new Jogador(Coord<float>(70, 90));
    jogador->pontos = pontos;

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

void Jogo::SalvarFase() {
    ofstream file;
    file.open("save.txt");
    int i, tam = pFaseAtual->listaEntidadesMoveis->getTamanho();

    file << to_string(faseAtual) + "\n";

    for (i = 0; i < tam; i++) {
        Entidade* e = (*(pFaseAtual->listaEntidadesMoveis))[i];
        char estado = '0';
        if (e->estaAtivo())
            estado = '1';
        if(e->getID() != projetil)
            file << to_string(e->getID()) + estado + ": " + to_string((int)e->getPosicao().x) + "-" + to_string((int)e->getPosicao().y) + "_" + "\n";
    }
    file.close();
}

void Jogo::CarregarFase() {
    ifstream file;
    file.open("save.txt");
    if(!file)
        return;

    string valor;
    file >> valor;
    Fase::faseAtual = stoi(valor);

    file.close();

    setFase(Fase::faseAtual, "save.txt");

    pMenuAtual = pMenuPrincipal;
}

void Jogo::SalvarRanking() {
    ofstream file;
    file.open("ranking.txt", ios::app);

    MenuNomeJogador* m = dynamic_cast<MenuNomeJogador*>(pMenuNomeJogador);
    file << m->getUltimoNome() + ":" + to_string(jogador->pontos) + "\n";

    file.close();
}

void Jogo::CarregarRanking() {
    ifstream file;
    file.open("ranking.txt");
    if(!file)
        return;

    pMenuRanking = new MenuRanking();
    string valor;
    while(getline(file, valor)){
        pMenuRanking->adicionarOpcao(valor);
    }
    
    file.close();

    pMenuRanking->Executar();
}