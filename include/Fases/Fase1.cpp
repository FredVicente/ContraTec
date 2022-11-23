#include "Fase1.h"

Fase1::Fase1(Jogador* p) : Fase(p) {}

void Fase1::Executar() {
    criarFase("Fase1.txt", player, Coord<int>(176, 14));

    gC.setLista(listaPlataformas, listaEntidadesMoveis);

    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(28);
}

int Fase1::PassarFase() {
    if (player->getPosicao().x > 1000) {
        //return 1;
    }
    return 0;
}