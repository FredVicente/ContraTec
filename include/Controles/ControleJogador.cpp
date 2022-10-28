#include "ControleJogador.h"
#include <Personagens/Jogador.h>

ControleJogador::ControleJogador(Entidades::Personagens::Jogador* pJ) :
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

void ControleJogador::notifyPressed(std::string tecla){
    if(pJogador == nullptr){
        std::cout << "ERRO: ponteiro para jogador nullptr." << std::endl;
            exit(7);
    }
    else
        std::cout << "dentro de ControleJogador:" << tecla << std::endl;

    /*if(tecla == up)
        pJogador->setDirecao("y", 1);
    else if(tecla == down)
        pJogador->setDirecao("y", -1);
    else if(tecla == right)
        pJogador->setDirecao("x", 1);
    else if(tecla == left)
        pJogador->setDirecao("x", -1);
    else if(tecla == attack)
        pJogador->setAtacando(true);*/
}

void ControleJogador::notifyReleased(std::string tecla){
    if(pJogador == nullptr){
        std::cout << "ERRO: ponteiro para jogador nullptr." << std::endl;
            exit(7);
    }
    else
        std::cout << "dentro de ControleJogador:" << tecla << std::endl;

    /*if(tecla == up)
        pJogador->setDirecao("y", 0);
    else if(tecla == down)
        pJogador->setDirecao("y", 0);
    else if(tecla == right)
        pJogador->setDirecao("x", 0);
    else if(tecla == left)
        pJogador->setDirecao("x", 0);
    else if(tecla == attack)
        pJogador->setAtacando(false);*/
}