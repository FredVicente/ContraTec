#pragma once

#include <Menu.h>
#include <ElementosGraficos/Input.h>
#include <ElementosGraficos/Botao.h>

using namespace ElementosGraficos;

class MenuNomeJogador : public Menu{
private:
    Input* input;
    Botao* botao;
public:
    MenuNomeJogador() : Menu(), input(nullptr), botao(nullptr) {
        Executar();
    };
    ~MenuNomeJogador() {};

    int Alterar(sf::Event e){
        if(e.type == sf::Event::TextEntered){
            input->addText(e.text.unicode);
        }
        else if(e.type == sf::Event::MouseButtonPressed){
            int posX = botao->getPosicao().x;
            int posY = botao->getPosicao().y;

            if((e.mouseButton.x > posX) && (e.mouseButton.x < (posX + botao->getTamanho().x)))
                if((e.mouseButton.y > posY) && (e.mouseButton.y < (posY + botao->getTamanho().y)))
                    return salvarJogo;
        }
        return -1;
    }

    void Executar(){
        if (font.loadFromFile("Fonts/PixelFont2.ttf")) 
            cout << "fonte importada" <<endl;
        else{
            cout << "ERROR: Could not load font.";
            exit(1);
        }

        input = new Input(font, Coord<int>(25,50));
        botao = new Botao(font, Coord<int>(50,150), "Salvar");
    };

     void Atualizar(){
        input->imprimir();
        botao->imprimir();
        gGrafico->centralizarView(0);
    };
};