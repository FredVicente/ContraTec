#pragma once
#include <Gerenciadores/GerenciadorGrafico.h>
#include <Animador/Imagem.h>

using namespace Gerenciadores;

namespace Animador {

    class Animacao {
    private:
        sf::RectangleShape* corpo;
        std::map<std::string, Imagem*> mapImagem;
        sf::Clock relogio;
        std::string imgAtual;
    public:
        Animacao(sf::RectangleShape* corpo);
        ~Animacao();
        void atualizar(const bool paraEsquerda, std::string imgAtual);
        void addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);
    };

}

