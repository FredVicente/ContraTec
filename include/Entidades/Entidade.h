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
		Coord<int> direcao;
		ID id;
		bool ativo = true;
	public:
		Entidade(Coord<float> pos, Coord<float> tam, ID id);
		Entidade() { id = vazio; shape = nullptr; };

		~Entidade() { delete(shape); };

		Coord<float> getPosicao() { return posicao; };
		Coord<float> getTamanho() { return tamanho; };
		sf::RectangleShape* getShape() { return shape; };
		int getID() { return id; };
		bool getEstado(){ return ativo; };
		void setEstado(bool valor){ ativo = valor; };
		void setPosicao(Coord<float> posicao);
		void setDirecao(std::string coordenada, int valor);

		virtual void Executar() = 0;
		virtual void Atualizar(float dt) = 0;
	};
}