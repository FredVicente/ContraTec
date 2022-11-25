#pragma once

#include "Inimigo.h"
#include <Entidades/Personagens/Jogador.h>

using namespace Entidades;
using namespace Fases;

//#define TAM_PROJ 30

namespace Entidades{
    class ReiRobo : public Inimigo{
    private:
        int nivelDeTirania;
        int vidaTotal;
        Jogador* player;
    public:
        ReiRobo(Coord<float> pos, Jogador* pJ = nullptr, int nivelT = 1);
        ~ReiRobo(){};

        void Atualizar(float dt);

        void receberDano();
    };
};