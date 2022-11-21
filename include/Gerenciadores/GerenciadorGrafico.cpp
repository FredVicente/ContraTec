#include "GerenciadorGrafico.h"

#include <cstring>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

namespace Gerenciadores {

    /* Singleton design pattern - Only one instance will be created */
    GerenciadorGrafico* GerenciadorGrafico::instancia = nullptr;

    /* Returns a pointer to the Graphics. */
    GerenciadorGrafico* GerenciadorGrafico::getInstancia() {
        if (instancia == nullptr) {
            instancia = new GerenciadorGrafico();
        }
        return instancia;
    }

    GerenciadorGrafico::GerenciadorGrafico() :
        window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "ContraTec", sf::Style::Titlebar | sf::Style::Close)),
        view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT))
    { }

    GerenciadorGrafico::~GerenciadorGrafico() {
        delete (window);
    }

    /* Give a pointer to a body and it will be drawn to the screen. */
    void GerenciadorGrafico::renderizar(sf::RectangleShape* body) {
        window->draw(*body);
    }

    /* Give a pointer to a Text and it will be drawn to the screen */
    void GerenciadorGrafico::renderizar(sf::Text* text) {
        window->draw(*text);
    }

    /* Display everything that was drawn. */
    void GerenciadorGrafico::display() {
        if (janelaAberta())
            window->display();
    }

    /* Clear the window to re-display stuff. */
    void GerenciadorGrafico::clear() {
        if (janelaAberta())
            window->clear();
    }

    /* Returns if the window is open. */
    bool GerenciadorGrafico::janelaAberta() const {
        return window->isOpen();
    }

    /* CAUTION: Call the close window function - SFML window will close. */
    void GerenciadorGrafico::fecharJanela() {
        window->close();
    }

    /* Sets window size to its parameters */
    void GerenciadorGrafico::setTamanhoJanela(Coord<int> size) {
        window->setSize(sf::Vector2u(size.x, size.y));
        view.setSize(size.x, size.y);
        window->setView(view);
    }

    /* Returns the window size. */
    Coord<int> GerenciadorGrafico::getTamanhoJanela() const {
        return Coord<int>(window->getSize().x, window->getSize().y);
    }

    /* Returns the top left position of screen. */
    /*Coord<float> GerenciadorGrafico::getTopLeftPosition() const {
        return Coord<float>(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
    }*/

    /* Changes the view position. */
    void GerenciadorGrafico::centralizarView(float posX) {
        view.setCenter(sf::Vector2f(posX, view.getCenter().y));
        window->setView(view);
    }
    void GerenciadorGrafico::centralizarView() {
        view.setCenter(sf::Vector2f(view.getCenter().x, view.getCenter().y));
        window->setView(view);
    }

    sf::RenderWindow* GerenciadorGrafico::getJanela() const {
        return window;
    }
}