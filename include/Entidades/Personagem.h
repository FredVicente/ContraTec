#pragma once
#include "Projetil.h"

namespace Entidades {
	class Personagem : public Entidade{
	protected:
		Coord<float> velocidade;
		Coord<float> aceleracao;
		Coord<int> direcao;
		int vidas;
		float dT;
	public:
		Personagem(Coord<float> posicao = Coord<float>(0, 0), Coord<float> tamanho = Coord<float>(0, 0), Coord<int> dir = Coord<int>(0, 0), ID id = vazio);
		~Personagem() {};

		void Executar() = 0;
		virtual void Atualizar(float dt) = 0;

		int getVidas() { return vidas; };

		void setVelocidade(std::string coordenada, int valor);
		void setDirecao(std::string coordenada, int valor);

		Coord<int> getDirecao() { return direcao; };

	 	void mover();
		void receberDano(){
			vidas--;
			std::cout << id << " Vidas: " << vidas << std::endl;
		}
	};
}
