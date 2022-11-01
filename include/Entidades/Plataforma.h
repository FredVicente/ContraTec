#pragma once
#include "Entidade.h"

namespace Entidades {
	class Plataforma : public Entidade {
	public:
<<<<<<< Updated upstream
		
=======
>>>>>>> Stashed changes
		Plataforma(Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f)) : Entidade(plataforma, posicao, tamanho) {};
		~Plataforma() {};

		void Executar() {};

<<<<<<< Updated upstream
=======
		// N�o h� a��es na colis�o da plataforma.
>>>>>>> Stashed changes
		void Colisao(Entidade* e, int dir) {};
	};
}

