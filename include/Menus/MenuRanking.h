#pragma once

#include <Menu.h>

class MenuRanking : public Menu{
private:
    sf::RectangleShape* botao;
public:
    MenuRanking() : Menu(){
        sf::Vector2f tamBotao = {120, 50};
        sf::Vector2f posBotao = sf::Vector2f(20 - (gGrafico->getTamanhoJanela().x / 2), 20);
        botao = new sf::RectangleShape(tamBotao);
        botao->setPosition(posBotao);
        botao->setFillColor(sf::Color::Yellow);
    };
    ~MenuRanking() {};

    void Executar(){
        if(!font.loadFromFile("Fonts/AstroSpace.ttf")) {
            cout << "ERROR: Could not load font.";
            system("pause");
        }
        textos.resize(opcoes.size()+1);

        int i;
        for(i = 0; i < opcoes.size(); i++){
            textos[i].setFont(font);
            textos[i].setString(opcoes[i]);
            textos[i].setPosition(sf::Vector2f(-(textos[i].getLocalBounds().width/2), 50 * (i+1)));
        }
        textos[i].setFont(font);
        textos[i].setString("Voltar");
        textos[i].setPosition(botao->getPosition());
        textos[i].setFillColor(sf::Color::Black);
    }

    int Alterar(sf::Event e) {
        if (e.type == sf::Event::MouseButtonPressed) {
            int posX = botao->getPosition().x;
            int posY = botao->getPosition().y;

            if (((e.mouseButton.x - gGrafico->getTamanhoJanela().x / 2) > posX) && ((e.mouseButton.x - gGrafico->getTamanhoJanela().x / 2) < (posX + botao->getSize().x)))
                if ((e.mouseButton.y > posY) && (e.mouseButton.y < (posY + botao->getSize().y)))
                    return menuPrincipal;
        }
        else if (e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::Escape)
                return menuPrincipal;
        }
        return -1;
    };

    void Atualizar(){
        gGrafico->renderizar(botao);
        int i;
        for(i = 0; i < textos.size(); i++){
            textos[i].setCharacterSize(24);
            gGrafico->renderizar(&(textos[i]));
        }
        gGrafico->centralizarView(0);
    };
};