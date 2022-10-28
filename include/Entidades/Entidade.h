#pragma once
#include "Ente.h"
#include <list> 
#define NAO_COLIDINDO 0
#define BAIXO 1
#define CIMA 2
#define DIREITA 3
#define ESQUERDA 4

namespace Entidades {
	enum ID {
		vazio = 0,
		jogador,
		plataforma,
		inimigo,
		projetil,
		imagem
	};
	class Entidade : public Ente{
	protected:
		ID id;
		sf::RectangleShape* shape;
		Coord<float> posicao;
		Coord<float> tamanho;
	public:
		static std::list<Entidade*> lista;

		Entidade(ID id, Coord<float> posicao, Coord<float> tamanho);
		~Entidade() { free(shape); };

		Coord<float> getPosicao() { return posicao; };
		Coord<float> getTamanho() { return tamanho; };
		sf::RectangleShape* getShape() { return shape; };
		int getID() { return id; };

		void setPosicao(Coord<float> posicao);

		void virtual Executar() = 0;

		void virtual Colisao(Entidade* e, int dir) = 0;
	};
}