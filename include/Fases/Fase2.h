#pragma once

#include "Fase.h"

using namespace Fases;

namespace Fases {
	class Fase2 : public Fase {
	public:
		Fase2();
		~Fase2() {};

		void executar();
		void atualizar(sf::View* view, sf::RenderWindow* window);
	};
}


