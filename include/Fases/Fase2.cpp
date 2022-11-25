#include "Fase2.h"

Fase2::Fase2(Jogador* p) : Fase(p) {}

void Fase2::Executar() {
    criarFase("Fase2.txt", player, Coord<int>(176, 12));

    gC.setLista(listaEntidadesEstaticas, listaEntidadesMoveis);

    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(28);
}

int Fase2::PassarFase() {
    return 0;
}
