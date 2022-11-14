#include "ControleJogador.h"
#include "Entidades/Personagens/Jogador.h"

ControleJogador::ControleJogador(Entidades::Jogador* pJ) :
    pJogador(pJ),
    jump("Space"),
    left("A"),
    right("D"),
    up("W"),
    down("S"),
    attack("1")
{
    return;
}

void ControleJogador::eventController(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::D)
                notifyPressed("D");
            else if (event.key.code == sf::Keyboard::A)
                notifyPressed("A");
            else if (event.key.code == sf::Keyboard::W && pJogador->pulo)
                notifyPressed("W");
            else if (event.key.code == sf::Keyboard::Num1)
                notifyPressed("1");
            break;

        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::D)
                notifyReleased("D");
            else if (event.key.code == sf::Keyboard::A)
                notifyReleased("A");
            else if (event.key.code == sf::Keyboard::W && pJogador->pulo)
                notifyReleased("W");
            else if (event.key.code == sf::Keyboard::Num1)
                notifyReleased("1");
            break;

        default:
            break;
    }
}

void ControleJogador::notifyPressed(std::string tecla) {
    if (pJogador == nullptr) {
        std::cout << "ERRO: ponteiro para jogador nullptr." << std::endl;
        exit(7);
    }

    if(tecla == right)
        pJogador->setDirecao("x", 1);
    else if(tecla == left)
        pJogador->setDirecao("x", -1);
    else if(tecla == up)
        pJogador->pular();
    else if(tecla == down)
        pJogador->setAgachado(true);
    else if(tecla == attack)
        pJogador->setAtacando(true);
}

void ControleJogador::notifyReleased(std::string tecla) {
    if (pJogador == nullptr) {
        std::cout << "ERRO: ponteiro para jogador nullptr." << std::endl;
        exit(7);
    }
    
    if(tecla == up)
        pJogador->setDirecao("y", 0);
    else if(tecla == right && pJogador->velocidade.x > 0 || tecla == left && pJogador->velocidade.x < 0)
        pJogador->setDirecao("x", 0);
    else if(tecla == down)
        pJogador->setAgachado(false);
    else if(tecla == attack)
        pJogador->setAtacando(false);
}