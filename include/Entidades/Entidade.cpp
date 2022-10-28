#include "Entidade.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

std::list<Entidade*> Entidade::lista;

Entidade::Entidade(Coord<float> posicao, Coord<float> tamanho, ID id) {
	this->posicao = posicao;
	this->tamanho = tamanho;
	this->id = id;
	lista.push_back(this);
	shape = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));
	setPosicao(posicao);
}

void Entidade::setPosicao(Coord<float> posicao) {
	this->posicao = posicao;
	(*shape).setPosition(posicao.x, posicao.y);
}