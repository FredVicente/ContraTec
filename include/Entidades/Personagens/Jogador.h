#pragma once
#include "Personagem.h"
#include <Controles/ControleJogador.h>

#include <iostream>
using namespace std;

namespace Entidades{

    namespace Personagens{

        class Jogador : public Personagem{
        private:
            Coord<int> direcao;
            bool atacando;
        public:

            Jogador(Coord<int> dir, Coord<float> posicao, Coord<float> tamanho);
            ~Jogador();

            void setDirecao(std::string coordenada, int valor);

            void setAtacando(bool valor);

            ControleJogador pControle;
        };
    }

}