#pragma once
#include "Ente.h"
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
		Coord<float> posicao;
		Coord<float> tamanho;
		sf::RectangleShape* shape;
		ID id;
	public:
<<<<<<< Updated upstream
		Entidade() { id = vazio; shape = NULL; };
		Entidade(Coord<float> posicao, Coord<float> tamanho, ID id);
=======
		Entidade() { id = vazio; shape = nullptr; };
		Entidade(Coord<float> pos, Coord<float> tam, ID id);
>>>>>>> Stashed changes
		~Entidade() { delete(shape); };

		Coord<float> getPosicao() { return posicao; };
		Coord<float> getTamanho() { return tamanho; };
		sf::RectangleShape* getShape() { return shape; };
		int getID() { return id; };
		void setPosicao(Coord<float> posicao);

		void virtual Executar() {};
		void virtual Colisao(Entidade* e, int dir) = 0;
	};
}