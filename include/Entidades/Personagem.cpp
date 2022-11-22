#include "Personagem.h"
#include "Listas/ListaEntidades.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Listas;
using namespace Fases;

Personagem::Personagem(Coord<float> posicao, Coord<float> tamanho, Coord<int> dir, ID id) : Entidade(posicao, tamanho, id) {
	aceleracao = Coord<float>(0, 0.5f);
	direcao = dir;
	faseAtual = nullptr;
	getShape()->setFillColor(sf::Color::Green);
}

//Retorna se est� no chao ou nao
void Personagem::ColisaoPlataforma(Entidade* e, int dir) {
	Coord<float> p1 = getPosicao();
	Coord<float> p2 = e->getPosicao();
	Coord<float> t1 = getTamanho();
	Coord<float> t2 = e->getTamanho();
	
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
	}
	else if (dir == CIMA) {
		setPosicao(Coord<float>(p1.x, p2.y + t2.y));
		velocidade.y = 0;
	}
}

void Personagem::mover() {
	Coord<float> dv;
	velocidade += aceleracao;
	dv.x = velocidade.x * direcao.x;
	dv.y = velocidade.y;
    setPosicao(posicao + dv);
}

void Personagem::setFase(Fase* f) {
	faseAtual = f;
};

void Personagem::setVelocidade(std::string coordenada, int valor) {
	if (coordenada == "x")
		velocidade.x = valor;
	else
		velocidade.y = valor;
}