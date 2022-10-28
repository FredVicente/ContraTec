#include "Jogador.h"

namespace Entidades{

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
    }

}