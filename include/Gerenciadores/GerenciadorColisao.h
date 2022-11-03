#pragma once
#include "Entidades/Entidade.h"
#include <list>

using namespace Entidades;

namespace Gerenciadores {
	class GerenciadorColisao
	{
	private:
		std::list<Entidade*>::iterator iterador1;
		std::list<Entidade*>::iterator iterador2;
	public:
		GerenciadorColisao() {};
		~GerenciadorColisao() {};

		// Testa a colisao entre todas a entidades do jogo.
		void Colisoes(std::list<Entidade*> l);

		// Testa a colisao entre duas entidades diretamente.
		int TestaColisao(Entidade* e1, Entidade* e2);
	};
}

