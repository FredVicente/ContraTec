#include "Jogo.h"

Jogo::Jogo() :
    jogador(Coord<float>(50,90))
{
    fase1 = nullptr;
    fase2 = nullptr;
    pFaseAtual = nullptr;

    vector<std::string> opMenu;
    opMenu.push_back("Jogar");
    opMenu.push_back("Continuar");
    opMenu.push_back("Sair");
    menu = new Menu(opMenu);
    menu->executar();

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
    // Gerenciador grafico.
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");
    sf::View view(sf::FloatRect(0, 0, janela.x, janela.y));

    if (!textura.loadFromFile("assets/Biker/Biker_attack1.png")) {
        cout << "ERROR: Texture";
    }
    
    

    sprite.setTexture(textura);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();

            if (state == playing) {
                jogador.pControle.eventController(event);
                if (event.KeyPressed && event.key.code == sf::Keyboard::P)
                    state = pause;
            }
            else {
                switch (menu->alterar(event)) {
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
                pFaseAtual->executar();
            }

            pFaseAtual->atualizar();
            pFaseAtual->imprimir(&view, &window);
        }
        else {
            window.clear();
            menu->atualizar(&window);
            view.setCenter(janela.x/2, janela.y/2);
            window.setView(view);
            window.draw(sprite);
            window.display();
        }
    }

    return;
}

void Jogo::salvar() {
    fstream file;
    file.open("save.txt", ios::out);
    file.write("pontos", 10);
    file.close();
}