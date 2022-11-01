#include "Principal.h"

using namespace Entidades::Personagens;

void Principal::Inicializar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");

    GerenciadorColisao *gC = new GerenciadorColisao();

    Coord<float> tamanho(50,120);
<<<<<<< Updated upstream
    Jogador* jogador1 = new Jogador(Coord<int>(0,0), Coord<float>(30,50), tamanho);
=======
    Entidades::Jogador* jogador1 = new Entidades::Jogador(Coord<int>(0,0), Coord<float>(30,50), tamanho);
>>>>>>> Stashed changes
    Plataforma* plataforma = new Plataforma(Coord<float>(200, 450), Coord<float>(200,50));
    Plataforma* plataforma2 = new Plataforma(Coord<float>(350, 350), Coord<float>(100, 50));
    Plataforma* plataforma3 = new Plataforma(Coord<float>(600, 300), Coord<float>(80, 50));
    Plataforma* chao = new Plataforma(Coord<float>(0, 500), Coord<float>(850, 50));
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
<<<<<<< Updated upstream
                if(event.type == sf::Event::TextEntered){
                    std::string keyString;
                    keyString = (char)event.text.unicode;
                    jogador1->pControle.notifyPressed(keyString);
                }

                if (event.key.code == sf::Keyboard::D)
                    jogador1->velocidade.x = 0.2f;
                if (event.key.code == sf::Keyboard::A)
                    jogador1->velocidade.x = -0.2f;
                if (event.key.code == sf::Keyboard::W && jogador1->pulo) {
                    jogador1->velocidade.y = -0.7;
                    jogador1->pulo = false;
                }
                break;
            case sf::Event::KeyReleased:
                if(event.type == sf::Event::TextEntered){
                    std::string keyString;
                    keyString = (char)event.text.unicode;
                    jogador1->pControle.notifyReleased(keyString);
                }
                if (event.key.code == sf::Keyboard::D && jogador1->velocidade.x > 0 ||
                    event.key.code == sf::Keyboard::A && jogador1->velocidade.x < 0)
                        jogador1->velocidade.x = 0;
=======

                if (event.key.code == sf::Keyboard::D)
                    jogador1->pControle.notifyPressed("D");
                else if (event.key.code == sf::Keyboard::A)
                    jogador1->pControle.notifyPressed("A");
                else if (event.key.code == sf::Keyboard::W && jogador1->pulo) 
                    jogador1->pControle.notifyPressed("W");
                else if (event.key.code == sf::Keyboard::Num1)
                    jogador1->pControle.notifyPressed("1");

                break;
            case sf::Event::KeyReleased:

                if (event.key.code == sf::Keyboard::D)
                    jogador1->pControle.notifyReleased("D");
                else if (event.key.code == sf::Keyboard::A)
                    jogador1->pControle.notifyReleased("A");
                else if (event.key.code == sf::Keyboard::W && jogador1->pulo) 
                    jogador1->pControle.notifyReleased("W");
                else if (event.key.code == sf::Keyboard::Num1)
                    jogador1->pControle.notifyReleased("1");
>>>>>>> Stashed changes
            default:
                break;
            }
        }
        window.clear();

        jogador1->Mover();

        gC->Colisoes();

        std::list<Entidade*>::iterator iterador = Entidade::lista.begin();;
        while (iterador != Entidade::lista.end()) {
            Entidade* entidade = NULL;
            entidade = *iterador;
            window.draw(*entidade->getShape());
            iterador++;
        }

        window.display();
    }

    return;
}