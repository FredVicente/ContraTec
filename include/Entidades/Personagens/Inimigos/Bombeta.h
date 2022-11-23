#pragma once
#include "Inimigo.h"

namespace Entidades {
	class Bombeta : public Inimigo {
	public:
		Bombeta(Coord<int> dir, Coord<float> posicao, Jogador* pJ)
		: Inimigo(dir, posicao, Coord<float>(50.f, 150.f), pJ, bombeta)
		{
			velocidade = Coord<float>(2, 0);
			getShape()->setFillColor(sf::Color::Cyan);
			vidas = 3;
		};

		~Bombeta() {};

		void Atualizar(float dt){
			if(vidas <= 0)
				ativo = false;
			else{
				velocidade.x = 2;
				if(player->getPosicao().x > posicao.x)
					direcao.x = 1;
				else
					direcao.x = -1;
				mover();
			}
		}
	};
}