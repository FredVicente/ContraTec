#pragma once
#include "Obstaculo.h"

namespace Entidades {
	class Plataforma : public Obstaculo {
	public:
		Plataforma(Coord<float> pos = Coord<float>(0.f, 0.f), Coord<float> tam = Coord<float>(50.0f, 50.0f)) : 
		Obstaculo(pos, tam, plataforma) {
			shape->setFillColor(sf::Color::White);
		};
		~Plataforma() {};

		void Inicializa(Coord<float> pos, Coord<float> tam, sf::Color cor);

		void Executar() {};
	};
}