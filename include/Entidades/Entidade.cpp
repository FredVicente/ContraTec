#include "Entidade.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Fases;

Entidade::Entidade(Coord<float> pos, Coord<float> tam, ID id) : ativo(true) {
	this->posicao = pos;
	this->tamanho = tam;
	this->id = id;
	shape = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));
	textura = nullptr;
	sprite = nullptr;
	setPosicao(pos);
}

void Entidade::setPosicao(Coord<float> posicao) {
	this->posicao = posicao;
	(*shape).setPosition(posicao.x, posicao.y);
}

void Entidade::setTextura(sf::String path) {
	textura = new sf::Texture;
	if (!textura->loadFromFile(path))
		std::cout << "ERROR: Caminho para textura nao existe!";
	else {
		sprite = new sf::Sprite();
		sprite->setTexture(*textura);
	}
}