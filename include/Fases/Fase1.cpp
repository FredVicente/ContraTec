#include "Fase1.h"

Fase1::Fase1(){
	player = nullptr;
}

void Fase1::executar() {
	listaEntidadesEstaticas = new ListaEntidades;
	listaEntidadesMoveis = new ListaEntidades;
	criarFase("Fase1.txt");
	listaEntidadesMoveis->adicionarEntidade(player);
	player->setPosicao(Coord<float>(400, 200));
}