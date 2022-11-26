#pragma once
#include "Obstaculo.h"

namespace Entidades {
	class Plataforma : public Obstaculo {
	public:
		Plataforma(Coord<float> pos = Coord<float>(0.f, 0.f), Coord<float> tam = Coord<float>(50.0f, 50.0f)) : 
		Obstaculo(pos, tam, plataforma) {
			shape->setFillColor(sf::Color::White);
			setTextura("assets/tile.png", sf::IntRect(0,0,32,32));
		};
		~Plataforma() {};
	};
}