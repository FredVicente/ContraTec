#include "Principal.h"

void Principal::Executar(){
    sf::Vector2f janela(800, 600);
    sf::RenderWindow window(sf::VideoMode(janela.x, janela.y), "Teste");

    ListaEntidades *lEntidades = new ListaEntidades();
    GerenciadorColisao *gC = new GerenciadorColisao();

    Coord<float> tamanho(50,120);
    Personagem* personagem = new Personagem(Coord<float>(30,50), tamanho);
    Plataforma* plataforma = new Plataforma(Coord<float>(200, 450), Coord<float>(200,50));
    Plataforma* plataforma2 = new Plataforma(Coord<float>(350, 350), Coord<float>(100, 50));
    Plataforma* plataforma3 = new Plataforma(Coord<float>(500, 350), Coord<float>(100, 50));
    Plataforma* chao = new Plataforma(Coord<float>(0, 500), Coord<float>(850, 50));

    lEntidades->lista.push_back(personagem);
    lEntidades->lista.push_back(plataforma);
    lEntidades->lista.push_back(plataforma2);
    lEntidades->lista.push_back(plataforma3);
    lEntidades->lista.push_back(chao);

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
                if (event.key.code == sf::Keyboard::W && personagem->colisao.y) {
                    personagem->velocidade.y = -0.7;
                    personagem->colisao.y = false;
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

        gC->Colisao(lEntidades);

        std::list<Entidade*>::iterator iterador = lEntidades->lista.begin();;
        while (iterador != lEntidades->lista.end()) {
            Entidade* entidade = NULL;
            entidade = *iterador;
            window.draw(*entidade->shape);
            iterador++;
        }

        window.display();
    }

    return;
}
