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
        int pontos;

        Jogador(Coord<float> tamanho = Coord<float>(50,90));
        ~Jogador() {};

        void setDirecao(std::string coordenada, int valor);

        void mover();

        void setAtacando(bool valor);

        void pular();

        void setAgachado(bool valor);

        void executar() {};

        ControleJogador pControle;
    };
}