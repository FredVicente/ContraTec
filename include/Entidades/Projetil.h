#pragma once
#include "Entidade.h"

namespace Entidades {
	class Projetil : public Entidade {
	private:
		Coord<float> velocidade;
		Coord<int> direcao;
		ID atirador;
	public:
		Projetil(int vel, Coord<int> dir, Coord<float> pos, Coord<float> tam, ID at) :
		Entidade(pos, tam, projetil),
		atirador(at)
		{
			direcao = dir;
			velocidade = Coord<float>(vel * direcao.x, vel * direcao.y);
			getShape()->setFillColor(sf::Color::Red);
		};

		ID getAtirador(){ return atirador; };

		void mover() { setPosicao(posicao + velocidade); }
		void Atualizar(float dt){ mover(); };

		void Executar(){};

		~Projetil(){};
	};
}