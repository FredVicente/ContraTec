#include "Entidade.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

Entidade::Entidade(ID id, Coord<float> posicao, Coord<float> tamanho) {
	this->posicao = posicao;
	this->tamanho = tamanho;
	this->id = id;
	shape = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));
	setPosicao(posicao);
}

void Entidade::setPosicao(Coord<float> posicao) {
	this->posicao = posicao;
	(*shape).setPosition(posicao.x, posicao.y);
}