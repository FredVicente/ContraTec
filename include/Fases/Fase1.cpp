#include "Fase1.h"

Fase1::Fase1(){
	player = nullptr;
}

<<<<<<< Updated upstream
void Fase1::Executar() {
	listaEntidadesEstaticas = new ListaEntidades;
	listaEntidadesMoveis = new ListaEntidades;
	criarFase("Fase1.txt");
	listaEntidadesMoveis->adicionarEntidade(player);
=======
int Fase1::PassarFase() {
    if (player->getPosicao().x > 2000) {
        return 1;
    }
    return 0;
>>>>>>> Stashed changes
}