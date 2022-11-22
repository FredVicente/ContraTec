#include "Menu.h"

Menu::Menu(vector<std::string> op) { 
    opcoes = { op[0], op[1], op[2] };
}

void Menu::Executar() {
    if (!font.loadFromFile("Fonts/PixelFont2.ttf")) {
        cout << "ERROR: Could not load font.";
        exit(1);
    }
    
    posicoes = { {350, 150}, {350, 300}, {350, 450} };

    textos.resize(3);
    int i;
    for (i = 0; i < textos.size(); i++) {
        textos[i].setFont(font);
        textos[i].setString(opcoes[i]);
        textos[i].setPosition(posicoes[i]);
    }
}

void Menu::atualizar(sf::RenderWindow* window) {
    int i;
    for (i = 0; i < opcoes.size(); i++) {
        window->draw(textos[i]);
        if (i == selected)
            textos[i].setCharacterSize(36);
        else
            textos[i].setCharacterSize(28);
    }
}

int Menu::alterar(sf::Event e) {
    int i = 0;
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::S || e.key.code == sf::Keyboard::Down)
            i = 1;
        else if (e.key.code == sf::Keyboard::W || e.key.code == sf::Keyboard::Up)
            i = -1;
        else if (e.key.code == sf::Keyboard::Enter || e.key.code == sf::Keyboard::Space)
            return selected+1;
    }
    
    selected += i;
    if (selected >= opcoes.size())
        selected = 0;
    else if (selected < 0)
        selected = opcoes.size() - 1;

    return 0;
}
