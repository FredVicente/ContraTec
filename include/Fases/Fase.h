#pragma once

#include "Ente.h"
#include "Entidades/Plataforma.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorColisao.h"
#include <list>

using namespace Gerenciadores;
using namespace Entidades;

namespace Fases {
	class Fase : public Ente {
	public:
		GerenciadorColisao gC;
		std::list<Entidade*> lista;

		Fase() {};
		~Fase() {};

		void virtual Executar() = 0;
	};
}
