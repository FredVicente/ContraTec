#pragma once
#include "Gerenciadores/GerenciadorGrafico.h"
/*
* Baseado no codigo do atual monitor de 
* engenharia da computação, Giovane Limas Salvi.
*/

using namespace Gerenciadores;

namespace Animador{
    class Imagem {
    private:
        GerenciadorGrafico* gGrafico;
        sf::Texture textura;
        sf::IntRect tamanho;
        const sf::Vector2f escala;
        const unsigned int qtdImagem;
        unsigned int imgAtual;
        const float tempoTroca;
        float tempoTotal;
    public:
        Imagem(const char* caminhoTextura, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);
        ~Imagem();
        void Atualizar(const bool paraEsquerda, const float dt);
        void resetar();
        const sf::IntRect getTamanho() const;
        const sf::Texture* getTextura() const;
        const sf::Vector2f getEscala() const;
    };

}

