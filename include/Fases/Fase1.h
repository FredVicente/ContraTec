#pragma once

#include "Fase.h"

using namespace Entidades;
using namespace Fases;
using namespace Listas;

namespace Fases {
	class Fase1 : public Fase {
	public:
		Fase1();
		~Fase1() {};

		void Executar();
	};
}