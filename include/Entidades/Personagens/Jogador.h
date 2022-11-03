#pragma once

#include <Entidades/Personagem.h>
#include <Controles/ControleJogador.h>

#include <iostream>
using namespace std;

namespace Entidades{
    class Jogador : public Personagem{
    private:
        Coord<int> direcao;
        bool atacando;
        bool agachado;
    public:

        Jogador(Coord<int> dir, Coord<float> posicao, Coord<float> tamanho);
        ~Jogador();

        void setDirecao(std::string coordenada, int valor);

        void setAtacando(bool valor);

        void pular();

        void setAgachado(bool valor);

        ControleJogador pControle;
    };
}