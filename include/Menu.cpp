#include "Menu.h"

Menu::Menu(vector<std::string> op) : Ente() { 
    int i, size = op.size();
    for(i = 0; i < size; i++)
        opcoes.push_back(op[i]);
}

void Menu::Executar() {
    if(!font.loadFromFile("Fonts/AstroSpace.ttf")){
        cout << "ERROR: Could not load font menu.";
        system("pause");
    }

    textos.resize(opcoes.size());
    int i;
    for (i = 0; i < textos.size(); i++) {
        textos[i].setFont(font);
        textos[i].setString(opcoes[i]);
        textos[i].setPosition(sf::Vector2f(-20, 125 * (i + 1)));
    }
}

void Menu::Atualizar() {
    int i;
    for (i = 0; i < opcoes.size(); i++) {
        gGrafico->renderizar(&(textos[i]));
        if (i == selected)
            textos[i].setCharacterSize(36);
        else
            textos[i].setCharacterSize(28);
    }

    gGrafico->centralizarView(0);
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
