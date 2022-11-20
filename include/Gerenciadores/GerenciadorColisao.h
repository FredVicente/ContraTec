#pragma once
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

namespace Gerenciadores {
	class GerenciadorColisao
	{
	public:
		ListaEntidades* listaMoveis;
		ListaEntidades* listaEstatica;

		GerenciadorColisao() { listaMoveis = nullptr; listaEstatica = nullptr; };
		~GerenciadorColisao() {};

		// Testa a colisao entre todas a entidades do jogo.
		void colisoes();

		// Testa a colisao entre duas entidades diretamente.
		int testaColisao(Entidade* e1, Entidade* e2);

		void setLista(ListaEntidades* lM, ListaEntidades* lE);
	};
}

