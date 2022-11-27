#pragma once
#include <Entidades/Projetil.h>

namespace Entidades {
	class Personagem : public Entidade{
	protected:
		Coord<float> velocidade;
		Coord<float> aceleracao;
		Coord<int> direcao;
		int vidas;
	public:
		Personagem(Coord<float> posicao = {0,0}, Coord<float> tamanho = {0,0}, Coord<int> dir = {0,0}, ID id = vazio);
		~Personagem() {};

		void Executar() = 0;
		virtual void Atualizar(float dt) = 0;

		int getVidas() { return vidas; };

		void setVelocidade(std::string coordenada, int valor);
		void setDirecao(std::string coordenada, int valor);

		Coord<int> getDirecao() { return direcao; };

	 	void mover();
		virtual void receberDano(){
			vidas--;
		}
	};
}
