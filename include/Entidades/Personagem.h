#pragma once
#include "Entidade.h"

namespace Entidades {
	class Personagem : public Entidade{
	public:
		Coord<float> velocidade;
		Coord<float> aceleracao;
		int vidas = 3;
		bool pulo = false;
		bool andando = false;

		Personagem(Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f), ID id = vazio);
		~Personagem() {};

		void Executar() {};

		void Mover();

		void Colisao(Entidade* e, int dir);
	};
}
