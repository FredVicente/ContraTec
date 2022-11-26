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
	setTamanho(tam);
	this->id = id;
}

void Entidade::setTextura(sf::String path, sf::IntRect tamanhoImagem) {
	textura = new sf::Texture;
	if (!textura->loadFromFile((path), tamanhoImagem))
		std::cout << "ERROR: Caminho para textura nao existe!";
	else {
		sprite = new sf::Sprite();
		sprite->setTexture(*textura);
		sprite->setPosition(posicao.x, posicao.y);
		const sf::Vector2f escala = sf::Vector2f(tamanho.x / textura->getSize().x, tamanho.y / textura->getSize().y);
		sprite->setScale(escala);
	}
}

void Entidade::setPosicao(Coord<float> pos) {
	this->posicao = pos;
	(*shape).setPosition(pos.x, pos.y);
}

void Entidade::setTamanho(Coord<float> tam) {
	this->tamanho = tam;
	(*shape).setSize(sf::Vector2f(tam.x, tam.y));
}