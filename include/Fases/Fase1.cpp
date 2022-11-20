#include "Fase1.h"

Fase1::Fase1(Jogador* p){
    listaEntidadesEstaticas = new ListaEntidades;
    listaEntidadesMoveis = new ListaEntidades;
    player = p;
}

void Fase1::executar() {
    criarFase("Fase1.txt", player, Coord<int>(176, 12));

    gC.setLista(listaEntidadesMoveis, listaEntidadesEstaticas);

    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(28);
}

void Fase1::atualizar() {
    player->mover();

    gC.colisoes();

    if (player->getPosicao().x > 2200) {
        Fase::faseAtual = 2;
    }
}