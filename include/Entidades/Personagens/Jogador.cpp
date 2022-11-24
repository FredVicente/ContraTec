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
    velocidade.x = 4 * direcao.x;
    velocidade += aceleracao;
    Coord<float> pos = getPosicao();
    setPosicao(pos + velocidade);
}

<<<<<<< Updated upstream
void Jogador::setAtacando(bool valor){
    if(valor)
        std::cout << "esta atacando" << std::endl;
    else
        std::cout << "nao esta atacando" << std::endl;
}
=======
void Jogador::Executar() {}

void Jogador::Atualizar(float dt) {
    if(vidas <= 0)
        ativo = false;
    else{
        dT += dt;

        if(dT > 2000){
            if (faseAtual && atacando) {
                Projetil* p;
                if(velocidade.x == 0 && direcao.y != 0)
                    p = new Projetil(10, Coord<int>(0,-1), posicao + Coord<float>(20, 20), Coord<float>(20, 20), jogador);
                else
                    p = new Projetil(10, direcao, posicao, Coord<float>(20, 20), jogador);

                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
            }
            dT = 0;
        }

        if(invencivel){
            tempoInvencivel += dt;
>>>>>>> Stashed changes

void Jogador::pular(){
    velocidade.y = -15;
    pulo = false;
}

void Jogador::setAgachado(bool valor){
    // Diminuir altura
    agachado = valor;
}