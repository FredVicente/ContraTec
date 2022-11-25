#pragma once
#include <list>
#include "Entidades/Entidade.h"
#include "Lista.h"

using namespace Entidades;
using namespace Listas;

namespace Listas {
	class ListaEntidades {
	public:
		Lista<Entidade> lista;

		ListaEntidades() {};
		~ListaEntidades();
		
		void adicionarEntidade(Entidade* pEntidade);
		
		void removerEntidade(Entidade* pEntidade);
		
		void removerEntidade(int posicao);

		int getTamanho();

		Entidade* operator[](int posicao);

		void atualizaTodos(float dt, Coord<float> range = Coord<float>(800,700));
	};
}

