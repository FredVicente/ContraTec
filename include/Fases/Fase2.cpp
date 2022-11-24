#include "Fase2.h"

Fase2::Fase2(Jogador* p, string path) : Fase(p, path) {}

void Fase2::Executar() {
    criarFase("Fase2.txt", player, Coord<int>(176, 14));

    gC.setLista(listaPlataformas, listaEntidadesMoveis);
}

int Fase2::PassarFase() {
    return 0;
}
