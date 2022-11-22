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
		void Colisoes();

		// Testa a colisao entre duas entidades diretamente.
		int TestaColisao(Entidade* e1, Entidade* e2);

		void ColisaoJogadorInimigo(Entidade* e1, Entidade* e2);
		void ColisaoJogadorProjetil(Entidade* e1, Entidade* e2);
		void ColisaoInimigoProjetil(Entidade* e1, Entidade* e2);
		void ColisaoPersonagemPlataforma(Entidade* e1, Entidade* e2, int dir);
	};
}

