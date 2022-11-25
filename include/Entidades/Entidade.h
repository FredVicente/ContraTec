#pragma once
#include "Ente.h"
#include <iostream>
#define NAO_COLIDINDO 0
#define BAIXO 1
#define CIMA 2
#define DIREITA 3
#define ESQUERDA 4

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
		obstaculo
	};
	class Entidade : public Ente{
	protected:
		Coord<float> posicao;
		Coord<float> tamanho;
		sf::RectangleShape* shape;
		sf::Texture* textura;
		sf::Sprite* sprite;
		Coord<int> direcao;
		ID id;
		bool ativo = true;
		bool range = true;
		Fases::Fase* faseAtual;
	public:
		Entidade(Coord<float> pos, Coord<float> tam, ID id);
		Entidade() { id = vazio; shape = nullptr; };

		~Entidade() { delete(shape); };

		Coord<float> getPosicao() { return posicao; };
		Coord<float> getTamanho() { return tamanho; };
		sf::RectangleShape* getShape() { return shape; };
		int getID() { return id; };
		bool getEstado(){ return ativo; };
		bool getRange(){ return range; };
		void setEstado(bool valor){ ativo = valor; };
		void setRange(bool valor){ range = valor; };
		void setPosicao(Coord<float> posicao);
		void setFase(Fases::Fase* f) { faseAtual = f; };
		void setTextura(sf::String path, sf::IntRect tamanhoImagem);
		Fases::Fase* getFase() { return faseAtual; };

		void virtual Executar() = 0;
		void virtual Atualizar(float dt) = 0;
		void imprimir() {
			if (sprite)
				GerenciadorGrafico::getInstancia()->renderizar(sprite);
			else
				GerenciadorGrafico::getInstancia()->renderizar(shape);
		};
	};
}