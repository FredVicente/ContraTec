#pragma once
#include "Projetil.h"

namespace Fases {
	class Fase;
}

namespace Entidades {
	class Personagem : public Entidade{
	protected:
		Coord<float> velocidade;
		Coord<float> aceleracao;
		int vidas;

		Fases::Fase* faseAtual;
		float dT;
	public:
		Personagem(Coord<float> posicao = Coord<float>(0, 0), Coord<float> tamanho = Coord<float>(0, 0), Coord<int> dir = Coord<int>(0, 0), ID id = vazio);
		~Personagem() {};

		virtual void Executar() = 0;
		virtual void Atualizar(float dt) = 0;

		void setFase(Fases::Fase* f);

		void setVelocidade(std::string coordenada, int valor);

	 	void mover();
		void receberDano(){
			vidas--;
			std::cout << id << " Vidas: " << vidas << std::endl;
		}
		void ColisaoPlataforma(Entidade* e, int dir);
	};
}