#pragma once
#include <Entidades/Personagens/Jogador.h>

namespace Entidades {
	class Inimigo : public Personagem {
	protected:
		Jogador* player;
	public:
		Inimigo(Coord<int> dir, Coord<float> posicao, Coord<float> tamanho, Jogador* pJ, ID id);
		~Inimigo() {};

		void Executar() {};
		virtual void Atualizar(float dt) = 0;
	};
}