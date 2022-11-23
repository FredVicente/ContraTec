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

void ListaEntidades::atualizaTodos(float dt, Entidade* jogador) {
	int i, tam = getTamanho();
	Coord<float> pos, posJogador = jogador->getPosicao();
	for (i = 0; i < tam; i++) {
		Entidade* e = lista[i];
		pos = e->getPosicao();
		if (abs(pos.x - posJogador.x) < 500 && abs(pos.y - posJogador.y) < 400) {
			e->setRange(true);
			if (e->getEstado()) {
				e->Atualizar(dt);
				e->imprimir();
			}
		}
		else {
			e->setRange(false);
			if (e->getID() == projetil)
				e->setEstado(false);
		}
	}
}