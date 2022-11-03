#pragma once

#include "Fase.h"

using namespace Entidades;

namespace Fases {
	class Fase1 : public Fase {
	public:
		Jogador* player;
		Plataforma p1, p2, p3, p4;
	public:
		Fase1();
		~Fase1() {};

		void Executar() {};
	};
}


