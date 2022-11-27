#include "Jogador.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Fases;

Jogador::Jogador(Coord<float> tamanho) :
    Personagem( Coord<float>(0,0), tamanho, Coord<int>(1, 0), jogador),
    tempoInvencivel(0),
    pontos(0),
    invencivel(false),
    pControle(this){
        velocidade = Coord<float>(0, 0);
        podePular = true;
        vidas = 3;
        tempoVida = 700;
        anim.addAnimacao("assets/character/Idle.png", "PARADO", 4, 0.4f, sf::Vector2f(1.5f, 1));
        anim.addAnimacao("assets/character/Walk.png", "ANDANDO", 6, 0.1f, sf::Vector2f(1.5f, 1));
        anim.addAnimacao("assets/character/Attack_Front.png", "ATACANDO", 3, 0.1f, sf::Vector2f(1.5f, 1));
        anim.addAnimacao("assets/character/Attack_Front_Walking.png", "ATACANDO_ANDANDO", 6, 0.1f, sf::Vector2f(1.5f, 1));
        anim.addAnimacao("assets/character/Agachado.png", "AGACHADO", 1, 0.1f, sf::Vector2f(1.5f, 1.6f));
        anim.addAnimacao("assets/character/Attack_Agachado.png", "ATACANDO_AGACHADO", 3, 0.1f, sf::Vector2f(1.5f, 1.6f));
        anim.addAnimacao("assets/character/Death.png", "MORTO", 6, (tempoVida / 250) / 6, sf::Vector2f(1.5f, 1));
}

void Jogador::pular(){
    if (podePular) {
        velocidade.y = -8;
        podePular = false;
    }
}

void Jogador::agacharOuLevantar(bool a){
    if(podePular){
        if(a && !agachado && vidas > 0){
            setTamanho(Coord<float>(70, ALTURA_AGACHADO));
            setPosicao(Coord<float>(posicao.x, posicao.y + (ALTURA_NORMAL - ALTURA_AGACHADO)));
        }
        else if(!a && agachado){
            setTamanho(Coord<float>(70, ALTURA_NORMAL));
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
    if (vidas <= 0) {
        tempoVida -= dt;
        if (tempoVida < 0) {
            ativo = false;
            return;
        }
    }
    else{
        dT += dt;

        if(dT > 150){
            if (faseAtual && atacando) {
                Projetil* p;
                if(velocidade.x == 0 && direcao.y != 0)
                    p = new Projetil(10, Coord<int>(0,-1), posicao + Coord<float>(tamanho.x/2, tamanho.y/2 - TAM_PROJ/2), Coord<float>(TAM_PROJ, TAM_PROJ), jogador);
                else
                    p = new Projetil(10, direcao, posicao + Coord<float>(tamanho.x/2, tamanho.y/2 - TAM_PROJ/2), Coord<float>(TAM_PROJ, TAM_PROJ), jogador);

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

        setVelocidade("x", andando * 3);
        if(agachado)
            setVelocidade("x", 0);
        mover();
    }
    AtualizarAnimacao();
}

void Jogador::AtualizarAnimacao() {
    bool lado = false;
    shape->setOrigin(sf::Vector2f(0, 0));
    if (direcao.x < 0) {
        lado = true;
        shape->setOrigin(sf::Vector2f(25, 0));
    }
    if (vidas > 0) {
        if (!atacando) {
            if (!andando && !agachado)
                anim.atualizar(lado, "PARADO");
            else if (!agachado)
                anim.atualizar(lado, "ANDANDO");
            else {
                shape->setOrigin(sf::Vector2f(shape->getOrigin().x, 20));
                anim.atualizar(lado, "AGACHADO");
            }
        }
        else {
            if (!andando && !agachado)
                anim.atualizar(lado, "ATACANDO");
            else if(!agachado)
                anim.atualizar(lado, "ATACANDO_ANDANDO");
            else {
                shape->setOrigin(sf::Vector2f(shape->getOrigin().x, 20));
                anim.atualizar(lado, "ATACANDO_AGACHADO");
            }
        }
    }
    else
        anim.atualizar(lado, "MORTO");
}