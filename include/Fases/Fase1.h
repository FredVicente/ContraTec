#pragma once

#include "Fase.h"

using namespace Fases;

namespace Fases {
	class Fase1 : public Fase {
	public:
		Fase1(Jogador* p);
		~Fase1() {};

		void executar();
		void atualizar();
	};
}


