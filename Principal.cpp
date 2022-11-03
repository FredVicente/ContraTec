#include "Principal.h"

void Principal::Inicializar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");

    Coord<float> tamanho(50,120);
    Personagem* personagem = new  Personagem(Coord<float>(30,50), tamanho);
    fase1.player = personagem;
    fase1.lista.push_back(personagem);
    
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
                    personagem->pulo = false;
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

        fase1.gC.Colisoes(fase1.lista);

        std::list<Entidade*>::iterator iterador = fase1.lista.begin();
        while (iterador != fase1.lista.end()) {
            Entidade* entidade = *iterador;
            window.draw(*entidade->getShape());
            iterador++;
        }

        window.display();
    }

    return;
}
