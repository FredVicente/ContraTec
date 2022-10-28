#pragma once
#include "Entidade.h"

namespace Entidades {
	class Plataforma : public Entidade {
	public:
		
		Plataforma(Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f)) : Entidade(plataforma, posicao, tamanho) {};
		~Plataforma() {};

		void Executar() {};

		void Colisao(Entidade* e, int dir) {};
	};
}

