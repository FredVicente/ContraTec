#pragma once
#include "Lista.h"
#include "Entidades/Entidade.h"

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

		void atualizaTodos();
	};
}

