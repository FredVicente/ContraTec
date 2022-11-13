#include "Entidade.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

Entidade::Entidade(Coord<float> pos, Coord<float> tam, ID id) {
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