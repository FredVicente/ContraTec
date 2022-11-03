#include "Plataforma.h"

using namespace Entidades;

void Plataforma::Inicializa(Coord<float> pos, Coord<float> tam, sf::Color cor) {
	posicao = pos;
	tamanho = tam;
	shape = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));
	shape->setFillColor(sf::Color::White);
	setPosicao(pos);
}