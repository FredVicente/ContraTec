#pragma once
#include "Inimigo.h"

namespace Entidades {
	class Torreta : public Inimigo {
    private:
        float dT;
		float tempoTiro;
	public:
		Torreta(Coord<int> dir, Coord<float> posicao, Jogador* pJ);

		~Torreta() {};

		void Atualizar(float dt);

		void AtualizarAnimacao();
	};
}