#pragma once
#include <Entidades/Personagem.h>
#include <Controles/ControleJogador.h>
#include <iostream>

using namespace std;

namespace Entidades{
    class Jogador : public Personagem{
    private:
        bool agachado;
        bool atacando;
        bool andando;
        bool podePular;
        bool invencivel;
        float tempoInvencivel;
    public:
        Jogador(Coord<float> posicao, Coord<float> tamanho);
        ~Jogador() {};

        void Executar();
        void Atualizar(float dt);
        void pular();
        void setAtacando(bool valor){atacando = valor;};
        void setAndando(bool valor){ andando = valor; };
        void setAgachado(bool valor){ agachado = valor; };
        void setPulo(bool valor){ podePular = valor; }
        void setVelocidade(std::string coordenada, int valor);

        void executar() {};

        ControleJogador pControle;
    };
}