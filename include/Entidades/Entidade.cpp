#include "Entidade.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

Entidade::Entidade(Coord<float> posicao, Coord<float> tamanho, ID id) {
	this->posicao = posicao;
	this->tamanho = tamanho;
	this->id = id;
	colisao.x = false;
	colisao.y = false;
	shape = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));
	setPosicao(posicao);
}

void Entidade::setPosicao(Coord<float> posicao) {
	(*shape).setPosition(posicao.x, posicao.y);
}