#include "Menu.h"

Menu::Menu(vector<std::string> op) : Ente() { 
    opcoes = { op[0], op[1], op[2] };
}

void Menu::Executar() {
    if (!font.loadFromFile("Fonts/PixelFont2.ttf")) {
        cout << "ERROR: Could not load font.";
        exit(1);
    }
    
    posicoes = { {0, 150}, {0, 300}, {0, 450} };

    textos.resize(3);
    int i;
    for (i = 0; i < textos.size(); i++) {
        textos[i].setFont(font);
        textos[i].setString(opcoes[i]);
        textos[i].setPosition(posicoes[i]);
    }
}

void Menu::Atualizar() {
    sf::RenderWindow* window = gGrafico->getJanela();
    sf::View* view = gGrafico->getView();

    int i;
    for (i = 0; i < opcoes.size(); i++) {
        window->draw(textos[i]);
        if (i == selected)
            textos[i].setCharacterSize(36);
        else
            textos[i].setCharacterSize(28);
    }

    view->setCenter(0, view->getCenter().y);
    window->setView(*view);
}

int Menu::Alterar(sf::Event e) {
    int i = 0;
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::S || e.key.code == sf::Keyboard::Down)
            i = 1;
        else if (e.key.code == sf::Keyboard::W || e.key.code == sf::Keyboard::Up)
            i = -1;
        else if (e.key.code == sf::Keyboard::Enter || e.key.code == sf::Keyboard::Space)
            return menuEvent(selected);
    }
    
    selected += i;
    if (selected >= opcoes.size())
        selected = 0;
    else if (selected < 0)
        selected = opcoes.size() - 1;

    return -1;
}
