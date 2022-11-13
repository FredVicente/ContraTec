#include "Plataforma.h"

using namespace Entidades;

Plataforma::Plataforma(Coord<float> pos) : 
	Entidade(pos, Math::Coord<float>(50,50), plataforma) {
	shape->setFillColor(sf::Color::White);
}