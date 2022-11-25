#include "Personagem.h"
#include "Listas/ListaEntidades.h"
#include <Fases/Fase.h>

using namespace Entidades;
using namespace Listas;

Personagem::Personagem(Coord<float> posicao, Coord<float> tamanho, Coord<int> dir, ID id) :
	Entidade(posicao, tamanho, id) {
	direcao = dir;
	velocidade = Coord<float>(0, 0);
	aceleracao = Coord<float>(0, 0.2f);
	shape->setFillColor(sf::Color::Green);
}

void Personagem::mover() {
	Coord<float> dv;
	velocidade += aceleracao;
	dv.x = velocidade.x * direcao.x;
	dv.y = velocidade.y;
    setPosicao(posicao + dv);
}

void Personagem::setDirecao(std::string coordenada, int valor) {
	if (coordenada == "x")
		direcao.x = valor;
	else
		direcao.y = valor;
}

void Personagem::setVelocidade(std::string coordenada, int valor) {
	if (coordenada == "x")
		velocidade.x = valor;
	else
		velocidade.y = valor;
}