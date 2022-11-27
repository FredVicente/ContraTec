#include "Fase1.h"

Fase1::Fase1(Jogador* p, string path) : Fase(p, "assets/Background/3.1.png", path) {}

void Fase1::Executar() {
    criarFase("Fase1.txt", player, Coord<int>(176, 14));

    gC.setLista(listaPlataformas, listaEntidadesMoveis);
}

int Fase1::PassarFase() {
    if (player->getPosicao().x > 6000) {
        return 1;
    }
    return 0;
}