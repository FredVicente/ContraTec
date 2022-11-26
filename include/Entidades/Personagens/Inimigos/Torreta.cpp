#include "Torreta.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

Torreta::Torreta(Coord<int> dir, Coord<float> posicao, Jogador* pJ)
: Inimigo(dir, posicao, Coord<float>(50.f, 60.f), pJ, torreta)
{
    velocidade = Coord<float>(0, 0);
    getShape()->setFillColor(sf::Color::Yellow);
    vidas = 3;
    anim.addAnimacao("assets/torreta/idle.png", "PARADO", 4, 0.4f, sf::Vector2f(2, 2));
    shape->setOrigin(sf::Vector2f(0, 30));
};

void Torreta::Atualizar(float dt){
    if(vidas <= 0)
        ativo = false;
    else{
        dT += dt;
        if(dT > 4000){
            if (faseAtual) {
                Projetil* p = new Projetil(5, direcao, posicao, Coord<float>(20, 20), torreta);
                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
            }
            dT = 0;
        }

        mover();

        AtualizarAnimacao();
    }
};