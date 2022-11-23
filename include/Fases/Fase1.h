#pragma once

#include "Fase.h"

using namespace Fases;

namespace Fases {
	class Fase1 : public Fase {
	public:
		Fase1(Jogador* p = nullptr);
		~Fase1() {};

		void Executar();
		void Atualizar(float dt);
	};
}