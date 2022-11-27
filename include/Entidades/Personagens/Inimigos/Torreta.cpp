#include "Torreta.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

Torreta::Torreta(Coord<int> dir, Coord<float> posicao, Jogador* pJ)
: Inimigo(dir, posicao, Coord<float>(140.f, 140.f), pJ, torreta)
{
    velocidade = Coord<float>(0, 0);
    vidas = 3;
    tempoVida = 600;
    anim.addAnimacao("assets/torreta/torreta2_idle.png", "PARADO", 1, 0.2f, sf::Vector2f(1.2, 1.1));
    anim.addAnimacao("assets/torreta/torreta2.png", "MORTE", 4, (tempoVida / 250) / 4, sf::Vector2f(1.2, 1.1));
    shape->setOrigin(sf::Vector2f(15, 10));
};

void Torreta::Atualizar(float dt){
    if (vidas <= 0) {
        tempoVida -= dt;
        if (tempoVida < 0)
            ativo = false;
    }
    else{
        dT += dt;
        if(dT > 500){
            if (faseAtual) {
                Projetil* p = new Projetil(5, direcao, posicao + Coord<float>(tamanho.x / 2, tamanho.y / 2 - TAM_PROJ / 2), Coord<float>(15, 15), torreta);
                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
                tempoTiro = 0.2f;
            }
            dT = 0;
        }

        if (tempoTiro > 0)
            tempoTiro -= dt;

        mover();
    }
    AtualizarAnimacao();
};

void Torreta::AtualizarAnimacao() {
    if (vidas > 0)
        anim.atualizar(true, "PARADO");
    else
        anim.atualizar(true, "MORTE");
}