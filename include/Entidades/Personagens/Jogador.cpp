#include "Jogador.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

Jogador::Jogador(Coord<float> tamanho) :
    Personagem( Coord<float>(0,0), tamanho, Coord<int>(1, 0), jogador),
    tempoInvencivel(0),
    invencivel(false),
    pControle(this){
        velocidade = Coord<float>(0, 0);
        podePular = true;
        vidas = 3;
        anim.addAnimacao("assets/character/idle.png", "PARADO", 4, 0.4f, sf::Vector2f(2, 1));
        anim.addAnimacao("assets/character/walk.png", "ANDANDO", 6, 0.1f, sf::Vector2f(2, 1));
        //shape->setOrigin(sf::Vector2f(0,0));
}

void Jogador::pular(){
    if (podePular) {
        velocidade.y = -8;
        podePular = false;
    }
}

void Jogador::agacharOuLevantar(bool a){
    if(podePular){
        if(a && !agachado){
            setTamanho(Coord<float>(50, ALTURA_AGACHADO));
            setPosicao(Coord<float>(posicao.x, posicao.y + (ALTURA_NORMAL - ALTURA_AGACHADO)));
        }
        else if(!a && agachado){
            setTamanho(Coord<float>(50, ALTURA_NORMAL));
            setPosicao(Coord<float>(posicao.x, posicao.y - (ALTURA_NORMAL - ALTURA_AGACHADO)));
        }
        agachado = a;
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

        if(dT > 200){
            if (faseAtual && atacando) {
                Projetil* p;
                if(velocidade.x == 0 && direcao.y != 0)
                    p = new Projetil(10, Coord<int>(0,-1), posicao + Coord<float>(tamanho.x/2, tamanho.y/2 - TAM_PROJ/2), Coord<float>(TAM_PROJ, TAM_PROJ/2), jogador);
                else
                    p = new Projetil(10, direcao, posicao + Coord<float>(tamanho.x/2, tamanho.y/2 - TAM_PROJ/2), Coord<float>(TAM_PROJ, TAM_PROJ/2), jogador);

                faseAtual->listaEntidadesMoveis->adicionarEntidade(p);
            }
            dT = 0;
        }

        if(invencivel){
            tempoInvencivel += dt;

            if(tempoInvencivel >= 500){
                setInvencivel(false);
                tempoInvencivel = 0;
            }
        }

        setVelocidade("x", andando * 2);
        if(!agachado)
            mover();

         AtualizarAnimacao();
    }
}

void Jogador::AtualizarAnimacao() {
    bool lado = false;
    if (direcao.x < 0)
        lado = true;
    if (!andando)
        anim.atualizar(lado, "PARADO");
    else
        anim.atualizar(lado, "ANDANDO");
}