#pragma once

#include "Fase.h"

using namespace Fases;

namespace Fases {
	class Fase2 : public Fase {
	public:
		Fase2(Jogador* p = nullptr, string path = "");
		~Fase2() {};

		void Executar();
		int PassarFase();
	};
}


