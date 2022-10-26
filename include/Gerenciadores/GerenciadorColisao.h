#pragma once
#include <Listas/ListaEntidades.h>
#include <list>

using namespace Listas;

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
		void Colisoes();

		// Testa a colisao entre duas entidades diretamente.
		int TestaColisao(Entidade* e1, Entidade* e2);
	};
}

