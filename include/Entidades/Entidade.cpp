#include "Entidade.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

Entidade::Entidade(Coord<float> pos, Coord<float> tam, ID id) : ativo(true) {
	this->posicao = pos;
	this->tamanho = tam;
	this->id = id;
	shape = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));
	setPosicao(pos);
}

void Entidade::setPosicao(Coord<float> posicao) {
	this->posicao = posicao;
	(*shape).setPosition(posicao.x, posicao.y);
}

void Entidade::setDirecao(std::string coordenada, int valor) {
	if (coordenada == "x")
		direcao.x = valor;
	else
		direcao.y = valor;
}