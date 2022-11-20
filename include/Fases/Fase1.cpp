#include "Fase1.h"

Fase1::Fase1(){
    listaEntidadesEstaticas = new ListaEntidades;
    listaEntidadesMoveis = new ListaEntidades;
}

void Fase1::executar() {
    criarFase("Fase1.txt", player, Coord<int>(176, 12));

    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(28);
}

void Fase1::atualizar(sf::View* view, sf::RenderWindow* window) {
    // Gerenciador Grafico
    window->clear();

    player->mover();

    gC.colisoes(listaEntidadesEstaticas, listaEntidadesMoveis);

    // Gerenciador Grafico
    int i = 0;
    Entidade* e;
    for (i = 0; i < listaEntidadesMoveis->getTamanho(); i++) {
        e = (*listaEntidadesMoveis)[i];
        window->draw(*e->getShape());
    }
    for (i = 0; i < listaEntidadesEstaticas->getTamanho(); i++) {
        e = (*listaEntidadesEstaticas)[i];
        window->draw(*e->getShape());
    }

    vidas.setString("Vidas: " + to_string(player->vidas));
    vidas.setPosition(view->getCenter() - sf::Vector2f(window->getSize().x / 2 , window->getSize().y / 2));
    window->draw(vidas);

    // Gerenciador Grafico.
    view->setCenter(player->getPosicao().x + player->getTamanho().x / 2, view->getCenter().y);

    window->setView(*view);
    window->display();

    if (player->getPosicao().x > 2000) {
        Fase::faseAtual = 1;
    }
}