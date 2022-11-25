#pragma once
#include "Inimigo.h"

namespace Entidades {
	class Bombeta : public Inimigo {
	private:
		float velocidadeX;
	public:
		Bombeta(Coord<int> dir, Coord<float> posicao, Jogador* pJ)
		: Inimigo(dir, posicao, Coord<float>(50.f, 50.f), pJ, bombeta),
		velocidadeX(1)
		{
			velocidade = Coord<float>(velocidadeX, 0);
			getShape()->setFillColor(sf::Color::Cyan);
			vidas = 3;
			//setTextura("assets/bombeta/idle.png");
		};

		~Bombeta() {};

		void Atualizar(float dt){
			if(vidas <= 0)
				ativo = false;
			else{
				velocidade.x = velocidadeX;
				if(player->getPosicao().x > posicao.x)
					direcao.x = 1;
				else
					direcao.x = -1;
				mover();
			}
		}
	};
}