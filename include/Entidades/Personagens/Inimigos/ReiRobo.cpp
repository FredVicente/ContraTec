#include "ReiRobo.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

ReiRobo::ReiRobo(Coord<float> pos, Jogador* pJ, int nivelT)
: nivelDeTirania(nivelT),
player(pJ),
Inimigo(Coord<int>(-1,0), pos, Coord<float>(100,100), pJ, reiRobo){
    pontos = 200;
    vidas = 12 * nivelDeTirania;
    vidaTotal = vidas;
    velocidade = Coord<float>(1, 0);
    tempoVida = 600;
    anim.addAnimacao("assets/boss/idle.png", "PARADO", 4, 0.4f, sf::Vector2f(1.3, 1.3));
    anim.addAnimacao("assets/boss/walk.png", "ANDANDO", 6, 0.2f, sf::Vector2f(1.3, 1.3));
    anim.addAnimacao("assets/boss/attack.png", "ATACANDO", 6, 0.05f, sf::Vector2f(1.3, 1.3));
    anim.addAnimacao("assets/boss/walk-attack.png", "ATACANDO_ANDANDO", 6, 0.05f, sf::Vector2f(1.3, 1.3));
    anim.addAnimacao("assets/boss/death.png", "MORTE", 6, (tempoVida / 250) / 6, sf::Vector2f(1.3, 1.3));
};

void ReiRobo::Atualizar(float dt){
    if (vidas <= 0) {
        tempoVida -= dt;
        if (tempoVida < 0) {
            ativo = false;
            player->pontos += pontos;
            return;
        }
    }
    else{
        float distancia = player->getPosicao().x - posicao.x;
        if(distancia > 0)
            direcao.x = 1;
        else{
            direcao.x = -1;
            distancia *= -1;
        }
            
        dT += dt;
        
        if(dT > 1500/nivelDeTirania){
            if (faseAtual) {
                Projetil* p = new Projetil(5, direcao, posicao + Coord<float>(0,45 + tamanho.y / 10), Coord<float>(20, 20), reiRobo);
                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
                tempoTiro = 150;
            }
            dT = 0;
        }

        if (tempoTiro > 0)
            tempoTiro -= dt;
        
        if(distancia < 300)
            setVelocidade("x", 0);
        else
            setVelocidade("x", 1);
        mover();
    }
    AtualizarAnimacao();
};

void ReiRobo::receberDano(){
    vidas--;
    cout << vidas << endl;
    if(vidas == vidaTotal/3){
        setPosicao(Coord<float>(posicao.x - tamanho.x * 0.1f / 2, posicao.y - tamanho.y * 0.1f));
        setTamanho(Coord<float>(tamanho.x * 1.1f, tamanho.y * 1.1f));
        nivelDeTirania++;
    }
    else if(vidas == vidaTotal/2){
        setPosicao(Coord<float>(posicao.x - tamanho.x * 0.2f / 2, posicao.y - tamanho.y * 0.2f));
        setTamanho(Coord<float>(tamanho.x * 1.2f, tamanho.y * 1.2f));
        nivelDeTirania++;
    }
}

void ReiRobo::AtualizarAnimacao() {
    bool lado = false;
    shape->setOrigin(20, tamanho.y / 9 + 12);
    if (direcao.x < 0) {
        lado = true;
        shape->setOrigin(0, tamanho.y / 9 + 12);
    }
    if (vidas > 0){
        if (tempoTiro <= 0) {
            if (velocidade.x == 0)
                anim.atualizar(lado, "PARADO");
            else
                anim.atualizar(lado, "ANDANDO");
        }
        else {
            if(velocidade.x == 0)
                anim.atualizar(lado, "ATACANDO");
            else
                anim.atualizar(lado, "ATACANDO_ANDANDO");
        }
    }
    else
        anim.atualizar(true, "MORTE");
}