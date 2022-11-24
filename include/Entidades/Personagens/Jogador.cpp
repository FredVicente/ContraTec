#include "Jogador.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

Jogador::Jogador(Coord<float> tamanho) :
    Personagem( Coord<float>(0,0), tamanho, Coord<int>(1, 0), jogador),
    tempoInvencivel(0),
    invencivel(false),
    pControle(this) {
        velocidade = Coord<float>(0, 0);
        podePular = true;
        vidas = 3;
}

void Jogador::pular(){
    if (podePular) {
        velocidade.y = -8;
        podePular = false;
    }
}

void Jogador::setVelocidade(std::string coordenada, int valor) {
	if (coordenada == "x")
		velocidade.x = valor;
	else
		velocidade.y = valor;
}

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
                    p = new Projetil(5, Coord<int>(0,-1), posicao + Coord<float>(20, 0), Coord<float>(20, 20), jogador);
                else
                    p = new Projetil(5, direcao, posicao, Coord<float>(20, 20), jogador);

                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
            }
            dT = 0;
        }

        if(invencivel){
            tempoInvencivel += dt;

            if(tempoInvencivel >= 4000){
                invencivel = false;
                tempoInvencivel = 0;
            }
        }
        
        setVelocidade("x", andando * 2);
        mover();
    }
}
