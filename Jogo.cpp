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
        while (window->pollEvent(event))
            TestaEstado(event);

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

            if (!jogador->ativo || jogador->getPosicao().y > 1000) {
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

void Jogo::TestaEstado(sf::Event event) {
    if (event.type == sf::Event::Closed)
        gGrafico->fecharJanela();

    if (state == playing) {
        jogador->pControle.eventController(event);
        if (event.KeyPressed && event.key.code == sf::Keyboard::P) {
            state = pause;
            pMenuAtual = pMenuPause;
        }
    }
    else {
        switch (pMenuAtual->Alterar(event)) {
        case menuPrincipal:
            pMenuAtual = pMenuPrincipal;
            setFase(0);
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
        case carregarFase:
            try {
                CarregarFase();
            }
            catch (int value) {
                switch (value) {
                case 1:
                    cout << "ERRO: erro ao carregar entidade vazia na fase.\n";
                    break;
                default:
                    cout << "ERRO: erro ao tentar carregar fase.\n";
                    break;
                }
            }
            catch (...) {
                cout << "ERRO: erro ao tentar carregar fase.\n";
                pMenuAtual = pMenuPrincipal;
            }
            state = playing;
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
            try {
                SalvarFase();
            }
            catch (...) {
                cout << "ERRO: erro ao tentar salvar fase.\n";
            }
            state = playing;
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
    case(0):
        pFaseAtual = nullptr;
        delete(jogador);
        jogador = nullptr;
        break;
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
    if (pFaseAtual)
        pFaseAtual->Executar();   
}

void Jogo::SalvarFase() {
    ofstream file;
    file.open("save.txt");

    int i, tam = pFaseAtual->listaEntidadesMoveis->getTamanho();

    int pontos = 0;
    int vidas = 3;
    if (jogador) {
        pontos = jogador->pontos;
        vidas = jogador->getVidas();
    }

    file << to_string(faseAtual) + "\n";
    file << to_string(pontos) + "\n";
    file << to_string(vidas) + "\n";

    for (i = 0; i < tam; i++) {
        Entidade* e = (*(pFaseAtual->listaEntidadesMoveis))[i];
        string ativo = "0";
        if (e->ativo)
            ativo = "1";
        if(e->getID() != projetil)
            file << ativo + "\n" + to_string((int)e->getPosicao().x) + "\n" + to_string((int)e->getPosicao().y) + "\n" + to_string(e->getID()) + "\n";
    }

    tam = pFaseAtual->listaPlataformas->getTamanho();
    for (i = 0; i < tam; i++) {
        Entidade* e = (*(pFaseAtual->listaPlataformas))[i];
        int posy = 0;
        if (e->getID() == elevador)
            posy = (e->getTamanho().y - 30);
        else if (e->getID() == torreEletrica)
            posy = 100;
        file << "1\n" + to_string((int)e->getPosicao().x) + "\n" + to_string((int)e->getPosicao().y + posy) + "\n" + to_string(e->getID()) + "\n";
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

    int pontos = 0;
    file >> valor;
    pontos = stoi(valor);

    int vidas = 3;
    file >> valor;
    vidas = stoi(valor);

    file.close();

    setFase(Fase::faseAtual, "save.txt");

    jogador->pontos = pontos;
    jogador->setVidas(vidas);

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