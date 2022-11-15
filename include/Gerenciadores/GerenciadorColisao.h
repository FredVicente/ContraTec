#pragma once
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

namespace Gerenciadores {
	class GerenciadorColisao
	{
	public:
		GerenciadorColisao() {};
		~GerenciadorColisao() {};

		// Testa a colisao entre todas a entidades do jogo.
		void colisoes(ListaEntidades listaEstatica, ListaEntidades listaMoveis);

		// Testa a colisao entre duas entidades diretamente.
		int testaColisao(Entidade* e1, Entidade* e2);
	};
}

