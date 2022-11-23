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