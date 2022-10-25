#pragma once
#include "Ente.h"
#include <list>

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
	public:
		ID id;
		Coord<bool> colisao;
		sf::RectangleShape* shape;
		Coord<float> posicao;
		Coord<float> tamanho;
		static std::list<Entidade*> lista;

		Entidade(Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f), ID id = vazio);
		~Entidade() {};

		void setPosicao(Coord<float> posicao);

		void virtual Executar() = 0;
	};
}