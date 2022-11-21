#pragma once
#include "Lista.h"
#include "Entidades/Entidade.h"

using namespace Entidades;

namespace Listas {
	class ListaEntidades {
	public:
		Lista<Entidade> lista;

		ListaEntidades() {};
		~ListaEntidades() {};
		
		void adicionarEntidade(Entidade* pEntidade) {
			lista.adicionar(pEntidade);
		};
		
		void removerEntidade(Entidade* pEntidade) {
			lista.remover(pEntidade);
		};
		
		void removerEntidade(int posicao) {
			lista.remover((int)posicao);
		};

		int getTamanho() {
			return lista.getTamanho();
		};

		Entidade* operator[](int posicao) {
			return lista[posicao];
		};
		
	};
}

