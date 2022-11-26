#pragma once
#include "Obstaculo.h"

namespace Entidades {
	class Plataforma : public Obstaculo {
	public:
		Plataforma(Coord<float> pos = Coord<float>(0.f, 0.f), Coord<float> tam = Coord<float>(50.0f, 50.0f)) : 
		Obstaculo(pos, tam, plataforma){
			textura = gGrafico->carregarTextura("assets/tile.png");
			shape->setTexture(&textura);
		};
		~Plataforma() { };
	};
}