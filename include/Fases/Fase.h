#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"
#include "Gerenciadores/GerenciadorColisao.h"
#include "Math/Coord.h"

using namespace Gerenciadores;
using namespace Listas;
using namespace Entidades;

namespace Fases {
	class Fase : public Ente {
	public:
		GerenciadorColisao gC;
		ListaEntidades *listaEntidades;

		Fase() {};
		~Fase() {};

		void virtual Executar() {};

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio) {
			switch (id) {
			case (plataforma): {
				Plataforma* p = new Plataforma(pos);
				return p;
			}
			default:
				break;
			}
			return NULL;
		}
	};
}
