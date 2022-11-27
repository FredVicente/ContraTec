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
			vidas = 3;
			tempoVida = 600;
			anim.addAnimacao("assets/bombeta/walk.png", "ANDANDO", 4, 0.2f, sf::Vector2f(2.5f, 2.5f));
			anim.addAnimacao("assets/bombeta/death.png", "MORTE", 4, (tempoVida / 250) / 6, sf::Vector2f(2.5f, 2.5f));
		};

		~Bombeta() {};

		void Atualizar(float dt){
			if (vidas <= 0) {
				tempoVida -= dt;
				if (tempoVida < 0)
					ativo = false;
			}
			else{
				velocidade.x = velocidadeX;
				if(player->getPosicao().x > posicao.x)
					direcao.x = 1;
				else
					direcao.x = -1;
				mover();
			}
			AtualizarAnimacao();
		}

		void AtualizarAnimacao() {
			bool lado = false;
			shape->setOrigin(sf::Vector2f(10, 30));
			if (direcao.x < 0) {
				lado = true;
				shape->setOrigin(sf::Vector2f(20, 30));
			}

			if (vidas > 0)
				anim.atualizar(lado, "ANDANDO");
			else
				anim.atualizar(lado, "MORTE");
		};
	};
}