#include "Principal.h"

void Principal::Executar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");

    GerenciadorColisao *gC = new GerenciadorColisao();

    Coord<float> tamanho(50,120);
    Personagem* personagem = new Personagem(Coord<float>(30,50), tamanho);
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
                if (event.key.code == sf::Keyboard::D)
                    personagem->velocidade.x = 0.2f;
                if (event.key.code == sf::Keyboard::A)
                    personagem->velocidade.x = -0.2f;
                if (event.key.code == sf::Keyboard::W && personagem->pulo) {
                    personagem->velocidade.y = -0.7;
                }
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::D && personagem->velocidade.x > 0 ||
                    event.key.code == sf::Keyboard::A && personagem->velocidade.x < 0)
                        personagem->velocidade.x = 0;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.x)
            default:
                break;
            }
        }
        window.clear();

        personagem->Mover();

        gC->Colisoes();

        std::list<Entidade*>::iterator iterador = Entidade::lista.begin();;
        while (iterador != Entidade::lista.end()) {
            Entidade* entidade = NULL;
            entidade = *iterador;
            window.draw(*entidade->shape);
            iterador++;
        }

        window.display();
    }

    return;
}
