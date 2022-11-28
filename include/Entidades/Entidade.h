#pragma once
#include "Ente.h"
#include <iostream>
#define NAO_COLIDINDO 0
#define BAIXO 1
#define CIMA 2
#define DIREITA 3
#define ESQUERDA 4
#include "Animador/Animacao.h"

using namespace Animador;

namespace Fases {
	class Fase;
}

namespace Entidades {
	enum ID {
		vazio = 0,
		jogador,
		plataforma,
		projetil,
		imagem,
		bombeta,
		torreta,
		elevador,
		torreEletrica,
		reiRobo
	};
	class Entidade : public Ente{
	protected:
		Coord<float> posicao;
		Coord<float> tamanho;
		sf::RectangleShape* shape;
		Coord<int> direcao;
		ID id;
		Fases::Fase* faseAtual;
		float dT;
	public:
		bool ativo = true;
		bool range = true;

		Entidade(Coord<float> pos, Coord<float> tam, ID id);

		~Entidade() { delete(shape); };

		Coord<float> getPosicao() { return posicao; };
		Coord<float> getTamanho() { return tamanho; };
		sf::RectangleShape* getShape() { return shape; };
		int getID() { return id; };
		void setPosicao(Coord<float> posicao);
		void setTamanho(Coord<float> tam);
		void setFase(Fases::Fase* f) { faseAtual = f; };
		Fases::Fase* getFase() { return faseAtual; };

		void virtual Executar() = 0;
		void virtual Atualizar(float dt) = 0;
		void imprimir() { GerenciadorGrafico::getInstancia()->renderizar(shape); };
	};
}