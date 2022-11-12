#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"
#include "Gerenciadores/GerenciadorColisao.h"
#include "Listas/ListaEntidades.h"

using namespace Gerenciadores;
using namespace Listas;
using namespace Entidades;

namespace Fases {
	class Fase : public Ente {
	public:
		GerenciadorColisao gC;
		ListaEntidades listaEntidades;

		Fase() {};
		~Fase() {};

		void virtual Executar() = 0;
	};
}
