#include "Fase2.h"

Fase2::Fase2(Jogador* p) {
    listaEntidadesEstaticas = new ListaEntidades;
    listaEntidadesMoveis = new ListaEntidades;
    player = p;
}

void Fase2::Executar() {
    criarFase("Fase2.txt", player, Coord<int>(176, 12));

    gC.setLista(listaEntidadesMoveis, listaEntidadesEstaticas);

    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(28);
}

void Fase2::Atualizar(float dt) {
    player->mover();

    gC.colisoes();
}
