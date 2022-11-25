#include "ReiRobo.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

ReiRobo::ReiRobo(Coord<float> pos, Jogador* pJ, int nivelT)
: nivelDeTirania(nivelT),
player(pJ),
Inimigo(Coord<int>(-1,0), pos, Coord<float>(60,60), pJ, reiRobo){
    vidas = 6 * nivelDeTirania;
    vidaTotal = vidas;
    velocidade = Coord<float>(1, 0);
    shape->setFillColor(sf::Color::Blue);
};

void ReiRobo::Atualizar(float dt){
    if(vidas <= 0)
        ativo = false;
    else{
        if(player->getPosicao().x > posicao.x)
            direcao.x = 1;
        else
            direcao.x = -1;
        
        dT += dt;
        
        if(dT > 2000){
            if (faseAtual) {
                Projetil* p = new Projetil(5, direcao, posicao, Coord<float>(20, 20), reiRobo);
                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
            }
            dT = 0;
        }
        setVelocidade("x", 1);
        mover();
    }
};

void ReiRobo::receberDano(){
    vidas--;
    if(vidas <= vidaTotal/3){
        setTamanho(tamanho + tamanho/2);
    }
    else if(vidas <= vidaTotal/2){
        setTamanho(tamanho*2);
    }
}