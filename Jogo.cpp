#include "Jogo.h"

Jogo::Jogo() :
    jogador(Coord<float>(50,90)),
    gGrafico(gGrafico->getInstancia())
{
    fase1 = nullptr;
    fase2 = nullptr;
    pFaseAtual = nullptr;

    vector<std::string> opMenu;
    opMenu.push_back("Jogar");
    opMenu.push_back("Continuar");
    opMenu.push_back("Sair");
    menu = new Menu(opMenu);
    menu->Executar();

    /* Sistema pra salvar
    vector<std::string> opPause;
    opMenu.push_back("Continuar");
    opMenu.push_back("Salvar");
    opMenu.push_back("Sair");
    pauseMenu = new Menu(opMenu);
    pauseMenu->executar();
    */

    Inicializar();
}

void Jogo::Inicializar(){
    /*
    if (!textura.loadFromFile("assets/Biker/Biker_attack1.png")) {
        cout << "ERROR: Texture";
    }
    sprite.setTexture(textura);
    */
    sf::RenderWindow* window = gGrafico->getJanela();
    window->setView(*(gGrafico->getView()));
    carregar();
    // Vari�veis de tempo.
    float dt = 0;
    float tAnt = 0;

    while (gGrafico->janelaAberta()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                gGrafico->fecharJanela();

            if (state == playing) {
                jogador.pControle.eventController(event);
                if (event.KeyPressed && event.key.code == sf::Keyboard::P)
                    state = pause;
            }
            else {
                switch (menu->Alterar(event)) {
                    case 1:
                        state = playing;
                        break;
                    case 2:
                        salvar();
                        break;
                    case 3:
                        exit(0);
                        break;
                    default:
                        break;
                }
            }
        }

        gGrafico->clear();
        if (state == playing) {
            // Gerenciador geral para update.
            if (Fase::faseAtual != faseAtual) {
                if(pFaseAtual)
                    delete(pFaseAtual);
                faseAtual = Fase::faseAtual;

                switch (faseAtual) {
                case(1):
                    fase1 = new Fase1(&jogador);
                    pFaseAtual = fase1;
                    break;
                case(2):
                    fase2 = new Fase2(&jogador);
                    pFaseAtual = fase2;
                    break;
                default:
                    break;
                }
                pFaseAtual->Executar();
            }

            dt += (clock() - tAnt) / CLOCKS_PER_SEC;

            if (dt > 20) {
                pFaseAtual->Atualizar(dt);
                tAnt = dt;
                dt = 0;
            }
        }
        else {
            switch (menuAtual) {
            case 0:
                menu->Atualizar();
                window->display();
                break;
            //case 1:

            }
            
        }
    }

    return;
}

void Jogo::salvar() {
    ofstream file;
    file.open("save.txt");
    file << to_string(jogador.pontos);
    file.close();
}

void Jogo::carregar() {
    ifstream file;
    file.open("save.txt");
    if(!file)
        return;
    file >> jogador.pontos;
    file.close();
}