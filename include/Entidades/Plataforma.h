#pragma once
#include "Entidade.h"

namespace Entidades {
	class Plataforma : public Entidade {
	public:
		Plataforma(Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f)) : Entidade(posicao, tamanho, plataforma) {};
		~Plataforma() {};

		void Executar(Coord<float> pos, Coord<float> tam, sf::Color cor);

		// N�o h� a��es na colis�o da plataforma.
		void Colisao(Entidade* e, int dir) {};
	};
}

