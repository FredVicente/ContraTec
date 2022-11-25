#include "Entidade.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Fases;

Entidade::Entidade(Coord<float> pos, Coord<float> tam, ID id) : ativo(true) {
	shape = new sf::RectangleShape(sf::Vector2f(tam.x, tam.y));
	setPosicao(pos);
	setTamanho(tam);
	this->id = id;
}

void Entidade::setPosicao(Coord<float> pos) {
	this->posicao = pos;
	(*shape).setPosition(pos.x, pos.y);
}

void Entidade::setTamanho(Coord<float> tam) {
	this->tamanho = tam;
	(*shape).setSize(sf::Vector2f(tam.x, tam.y));
}