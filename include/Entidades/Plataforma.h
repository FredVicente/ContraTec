#pragma once
#include "Entidade.h"

namespace Entidades {
	class Plataforma : public Entidade {
	public:
<<<<<<< Updated upstream
		Plataforma(Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f)) : Entidade(posicao, tamanho, plataforma) {};
=======
		Plataforma(Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tam = Coord<float>(50.0f, 50.0f));
>>>>>>> Stashed changes
		~Plataforma() {};

		void Inicializa(Coord<float> pos, Coord<float> tam, sf::Color cor);

		void Executar() {};

		// Não há ações na colisão da plataforma.
		void Colisao(Entidade* e, int dir) {};
	};
}

