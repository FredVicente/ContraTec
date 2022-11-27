#pragma once

#include <Menu.h>
//#include <ElementosGraficos/Input.h>
//#include <ElementosGraficos/Botao.h>

//using namespace ElementosGraficos;

class MenuNomeJogador : public Menu{
private:
    sf::RectangleShape* input;
    sf::RectangleShape* botao;
    std::string textInput;
    std::string ultimoNome;
public:
    MenuNomeJogador() :
    Menu(),
    input(nullptr),
    botao(nullptr) {
        sf::Vector2f tamBotao = {120, 50};
        sf::Vector2f posBotao = {-(tamBotao.x/2), 300};

        sf::Vector2f tamInput = {300, 60};
        sf::Vector2f posInput = {-(tamInput.x/2), 150};

        input = new sf::RectangleShape(tamInput);
        botao = new sf::RectangleShape(tamBotao);

        input->setPosition(posInput);
        botao->setPosition(posBotao);

        botao->setFillColor(sf::Color::Yellow);

        input->setFillColor(sf::Color::Transparent);
        input->setOutlineThickness(5);

        Executar();
    };
    ~MenuNomeJogador() {};

    std::string getUltimoNome(){ return ultimoNome; };

    int Alterar(sf::Event e){
        if(e.type == sf::Event::TextEntered){
            if(e.text.unicode == '\b' && textInput.size() > 0)
                textInput.erase(textInput.size() - 1, 1);
            else if(textInput.size() <= 15)
                textInput += e.text.unicode;
            textos[0].setString(textInput);
        }
        else if(e.type == sf::Event::MouseButtonPressed){
            int posX = botao->getPosition().x;
            int posY = botao->getPosition().y;

            if(((e.mouseButton.x - gGrafico->getTamanhoJanela().x/2) > posX) && ((e.mouseButton.x - gGrafico->getTamanhoJanela().x/2) < (posX + botao->getSize().x)))
                if((e.mouseButton.y > posY) && (e.mouseButton.y < (posY + botao->getSize().y))){
                    ultimoNome = textInput;
                    textInput = "";
                    textos[0].setString(textInput);
                    return salvarRanking;
                }
        }
        else if(e.type == sf::Event::KeyPressed){
            if(e.key.code == sf::Keyboard::Enter){
                ultimoNome = textInput;
                    textInput = "";
                    textos[0].setString(textInput);
                    return salvarRanking;
            }
        }
        return -1;
    }

    void Executar(){
        if (!font.loadFromFile("Fonts/AstroSpace.ttf")){
            cout << "ERROR: Could not load font.";
            exit(1);
        }

        textos.resize(2);
        textos[0].setFont(font);
        textos[0].setString("");
        textos[0].setPosition(input->getPosition());

        textos[1].setFont(font);
        textos[1].setString("Salvar");
        textos[1].setPosition(botao->getPosition());
        textos[1].setFillColor(sf::Color::Black);
    };

    void Atualizar(){
        gGrafico->renderizar(input);
        gGrafico->renderizar(botao);
        int i;
        for(i = 0; i < 2; i++){
            textos[i].setCharacterSize(24);
            gGrafico->renderizar(&(textos[i]));
        }
        gGrafico->centralizarView(0);
    };
};