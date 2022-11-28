#include "Fase1.h"

Fase1::Fase1(Jogador* p, string path) : Fase(p, "assets/Background/3.1.png", path) {}

void Fase1::Executar() {
    criarFase("Fase1.txt", player, Coord<int>(173, 14));

    gC.setLista(listaPlataformas, listaEntidadesMoveis);
}

int Fase1::PassarFase() {
    if (player->getPosicao().x > 7700) {
        return 1;
    }
    return 0;
}