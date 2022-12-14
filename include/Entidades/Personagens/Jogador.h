#pragma once
#include "Personagem.h"
#include <Controles/ControleJogador.h>
#include <iostream>

#define ALTURA_NORMAL 90
#define ALTURA_AGACHADO 60
#define TAM_PROJ 15

using namespace std;

namespace Entidades{
    class Jogador : public Personagem{
    private:
        bool agachado;
        bool atacando;
        bool invencivel = false;
        float tempoInvencivel; 
    public:
        Jogador(Coord<float> tamanho = Coord<float>(50,90));
        ~Jogador() {};

        int andando;
        int pontos;
        bool podePular;
        ControleJogador pControle;

        void Executar();
        void Atualizar(float dt);
        void pular();
        bool getInvencivel(){ return invencivel; };
        void agacharOuLevantar(bool a);
        void setVidas(int valor){ vidas = valor; };
        void setAtacando(bool valor){
            if(!atacando)
                dT = 1000;
            atacando = valor;
        };
        void setInvencivel(bool valor){
            invencivel = valor;
            if(valor)
                shape->setFillColor(sf::Color::Red);
            else
                shape->setFillColor(sf::Color::White);
        }
        void setVelocidade(std::string coordenada, int valor);

        void receberDano(){
			if(!invencivel){
                vidas--;
                setInvencivel(true);
            }
		}
        
        void AtualizarAnimacao();
    };
}