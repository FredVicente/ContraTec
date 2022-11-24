#include "Jogo.h"

Jogo::Jogo() :
    jogador(Coord<float>(50,90)),
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

    Inicializar();
}

void Jogo::Inicializar(){

    pMenuAtual = pMenuPrincipal;
    
    sf::RenderWindow* window = gGrafico->getJanela();
    window->setView(*(gGrafico->getView()));
    carregar();

    float dt = 0;
    float tAnt = 0;

    while (gGrafico->janelaAberta()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                gGrafico->fecharJanela();

            if (state == playing) {
                jogador.pControle.eventController(event);
                if (event.KeyPressed && event.key.code == sf::Keyboard::P){
                    state = pause;
                    pMenuAtual = pMenuPause;
                }
                    
            }
            else {
                switch (pMenuAtual->Alterar(event)) {
                    case menu1:
                        pMenuAtual = pMenuPrincipal;
                        break;
                    case menu2:
                        pMenuAtual = pMenuFase;
                        break;
                    case entrarFase1:
                        state = playing;
                        faseAtual = 1;
                        break;
                    case entrarFase2:
                        state = playing;
                        faseAtual = 2;
                        break;
                    case entrarFaseAtual:
                        state = playing;
                        break;
                    case salvarJogo:
                        salvar();
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
            if (Fase::faseAtual != faseAtual || !pFaseAtual) {
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
            pMenuAtual->Atualizar();
            window->display();
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