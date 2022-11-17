#include "Jogador.h"

using namespace Entidades;

Jogador::Jogador(Coord<float> posicao, Coord<float> tamanho) :
    Personagem(posicao, tamanho, jogador),
    direcao(Coord<int>(0,0)),
    pControle(this) {
        velocidade = Coord<float>(0, 0);
}

void Jogador::setDirecao(std::string coordenada, int valor){
        if(coordenada == "x")
            direcao.x = valor;
        else
            direcao.y = valor;
}

void Jogador::mover() {
    velocidade.x = 10 * direcao.x;
    velocidade += aceleracao;
    Coord<float> pos = getPosicao();
    setPosicao(pos + velocidade);
}

void Jogador::setAtacando(bool valor){
    if(valor)
        std::cout << "esta atacando" << std::endl;
    else
        std::cout << "nao esta atacando" << std::endl;
}

void Jogador::pular(){
    velocidade.y = -20;
    pulo = false;
}

void Jogador::setAgachado(bool valor){
    // Diminuir altura
    agachado = valor;
}
