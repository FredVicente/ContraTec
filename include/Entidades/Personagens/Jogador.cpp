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
    velocidade.x = 6 * direcao.x;
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

void Jogador::colisao(Entidade* e, int dir) {
	int id = e->getID();
	if (id == inimigo) {
		// Implementar com inimigo.
	}

	Coord<float> p1 = getPosicao();
	Coord<float> p2 = e->getPosicao();
	Coord<float> t1 = getTamanho();
	Coord<float> t2 = e->getTamanho();
	if (id == plataforma) {
		if (dir == DIREITA) {
			setPosicao(Coord<float>(p2.x - t1.x, p1.y));
			velocidade.x = 0;
		}
		else if (dir == ESQUERDA) {
			setPosicao(Coord<float>(p2.x + t2.x, p1.y));
			velocidade.x = 0;
		}
		if (dir == BAIXO) {
			setPosicao(Coord<float>(p1.x, p2.y - t1.y));
			velocidade.y = 0;
			pulo = true;
		}
		else if (dir == CIMA) {
			setPosicao(Coord<float>(p1.x, p2.y + t2.y));
			velocidade.y = 0;
		}
	}
}