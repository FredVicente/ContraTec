#include "ListaEntidades.h"

ListaEntidades::~ListaEntidades() {
	lista.clear();
}

void ListaEntidades::adicionarEntidade(Entidade* pEntidade) {
	lista.adicionar(pEntidade);
}

void ListaEntidades::removerEntidade(Entidade* pEntidade) {
	lista.remover(pEntidade);
}

void ListaEntidades::removerEntidade(int posicao) {
	lista.remover((int)posicao);
}

int ListaEntidades::getTamanho() {
	return lista.getTamanho();
}

Entidade* ListaEntidades::operator[](int posicao) {
	return lista[posicao];
}

void ListaEntidades::atualizaTodos() {
	int i, tam = getTamanho();
	for (i = 0; i < tam; i++) {
		lista[i]->Executar();
	}
}