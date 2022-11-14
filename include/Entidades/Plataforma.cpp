#include "Plataforma.h"

using namespace Entidades;

Plataforma::Plataforma(Coord<float> pos, Coord<float> tam) : 
	Entidade(pos, tam, plataforma) {
	shape->setFillColor(sf::Color::White);
}