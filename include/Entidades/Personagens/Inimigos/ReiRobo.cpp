#include "ReiRobo.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

ReiRobo::ReiRobo(Coord<float> pos, Jogador* pJ, int nivelT)
: nivelDeTirania(nivelT),
player(pJ),
Inimigo(Coord<int>(-1,0), pos, Coord<float>(60,60), pJ, reiRobo){
    vidas = 12 * nivelDeTirania;
    vidaTotal = vidas;
    velocidade = Coord<float>(1, 0);
    shape->setFillColor(sf::Color::Blue);
};

void ReiRobo::Atualizar(float dt){
    if(vidas <= 0)
        ativo = false;
    else{
        float distancia = player->getPosicao().x - posicao.x;
        if(distancia > 0)
            direcao.x = 1;
        else{
            direcao.x = -1;
            distancia *= -1;
        }
            
        dT += dt;
        
        if(dT > 8000/nivelDeTirania){
            if (faseAtual) {
                Projetil* p = new Projetil(5, direcao, posicao, Coord<float>(20, 20), reiRobo);
                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
            }
            dT = 0;
        }
        
        if(distancia < 300)
            setVelocidade("x", 0);
        else
            setVelocidade("x", 1);
        mover();
    }
};

void ReiRobo::receberDano(){
    vidas--;
    cout << vidas << endl;
    if(vidas == vidaTotal/3){
        setTamanho(Coord<float>(tamanho.x, tamanho.y + tamanho.y/2));
        setPosicao(Coord<float>(posicao.x, posicao.y - (posicao.y + posicao.y/2)));
    }
    else if(vidas == vidaTotal/2){
        setTamanho(Coord<float>(tamanho.x + tamanho.x/2, tamanho.y*2));
        setPosicao(Coord<float>(posicao.x, posicao.y - posicao.y));
    }
}