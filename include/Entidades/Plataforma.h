#pragma once
#include "Entidade.h"

namespace Entidades {
	class Plataforma : public Entidade {
	public:
		Plataforma(Coord<float> posicao = Coord<float>(0.f, 0.f));
		~Plataforma() {};

		void Executar() {};

		// N�o h� a��es na colis�o da plataforma.
		void Colisao(Entidade* e, int dir) {};
	};
}

