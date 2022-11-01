#include "Jogador.h"

namespace Entidades{

<<<<<<< Updated upstream
    namespace Personagens{

        Jogador::Jogador(Coord<int> dir, Coord<float> posicao, Coord<float> tamanho) :
        Personagem(jogador, tamanho, posicao),
        direcao(dir),
        pControle(this) {
            return;
        }

        void Jogador::setDirecao(std::string coordenada, int valor){
            if(coordenada == "x")
                direcao.x = valor;
            else
                direcao.y = valor;
        }

        void Jogador::setAtacando(bool valor){
            if(valor)
                std::cout << "esta atacando" << std::endl;
            else
                std::cout << "nao esta atacando" << std::endl;
        }
=======
    Jogador::Jogador(Coord<int> dir, Coord<float> posicao, Coord<float> tamanho) :
    Personagem(jogador, tamanho, posicao),
    direcao(dir),
    pControle(this) {
        velocidade = Coord<float>(0.2 * dir.x, -0.7*dir.y);
    }

    void Jogador::setDirecao(std::string coordenada, int valor){
        if(coordenada == "x")
            direcao.x = valor;
        else
            direcao.y = valor;
        
        velocidade.x = 0.2 * direcao.x;
    }

    void Jogador::setAtacando(bool valor){
        if(valor)
            std::cout << "esta atacando" << std::endl;
        else
            std::cout << "nao esta atacando" << std::endl;
    }

    void Jogador::pular(){
        velocidade.y = -0.7;
        pulo = false;
    }

    void Jogador::setAgachado(bool valor){
        // Diminuir altura
        agachado = valor;
>>>>>>> Stashed changes
    }

}