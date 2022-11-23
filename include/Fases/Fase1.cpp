#include "Fase1.h"

Fase1::Fase1(Jogador* p){
    listaEntidadesEstaticas = new ListaEntidades;
    listaEntidadesMoveis = new ListaEntidades;
    player = p;
}

void Fase1::Executar() {
    criarFase("Fase1.txt", player, Coord<int>(176, 12));

    gC.setLista(listaEntidadesMoveis, listaEntidadesEstaticas);

    font.loadFromFile("Fonts/PixelFont2.ttf");
    vidas.setFont(font);
    vidas.setCharacterSize(28);
}

void Fase1::Atualizar(float dt) {
    int i;
    for(i = 0; i < listaEntidadesMoveis->getTamanho(); i++){
        Entidade* e = (*listaEntidadesMoveis)[i];
        e->Atualizar(dt);
    }

    gC.colisoes();
}
