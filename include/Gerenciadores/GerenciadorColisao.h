#pragma once
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

namespace Gerenciadores {
	class GerenciadorColisao
	{
	private:
		ListaEntidades* listaMoveis;
		ListaEntidades* listaEstatica;
	public:
		GerenciadorColisao() { listaMoveis = nullptr; listaEstatica = nullptr; };
		~GerenciadorColisao() {};

		void setLista(ListaEntidades* lE, ListaEntidades* lM);

		// Testa a colisao entre todas a entidades do jogo.
		void Colisoes();

		// Testa a colisao entre duas entidades diretamente.
		int TestaColisao(Entidade* e1, Entidade* e2);

		void ColisaoJogadorInimigo(Entidade* e1, Entidade* e2);
		void ColisaoJogadorProjetil(Entidade* e1, Entidade* e2);
		void ColisaoInimigoProjetil(Entidade* e1, Entidade* e2);
		void ColisaoPersonagemObstaculo(Entidade* e1, Entidade* e2, int dir);
		void ColisaoProjetilObstaculo(Entidade* e1);
	};
}

