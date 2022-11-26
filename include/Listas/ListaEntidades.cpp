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

void ListaEntidades::executarTodos() {
	int i, tam = getTamanho();
	for (i = 0; i < tam; i++) {
		Entidade* e = lista[i];
		e->Executar();
	}
}

void ListaEntidades::atualizaTodos(float dt, Coord<float> range) {
	int i, tam = getTamanho();
	Coord<float> pos, posView = Coord<float>(GerenciadorGrafico::getInstancia()->getView()->getCenter().x, 
											GerenciadorGrafico::getInstancia()->getView()->getCenter().y);
	for (i = 0; i < tam; i++) {
		Entidade* e = lista[i];
		pos = e->getPosicao();
		if (abs(pos.x - posView.x) < range.x && abs(pos.y - posView.y) < range.y) {
			e->setRange(true);
			if (e->estaAtivo()) {
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