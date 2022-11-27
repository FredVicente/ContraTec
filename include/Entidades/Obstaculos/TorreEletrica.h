#pragma once
#include "Obstaculo.h"

namespace Entidades {
	class TorreEletrica : public Obstaculo {
    private:
        float tempoDano;
        float altura;
	public:
		TorreEletrica(Coord<float> pos = Coord<float>(0.f, 0.f)) : 
        altura(200),
		Obstaculo(pos - Coord<float>(0, 100), Coord<float>(60, 200), torreEletrica),
        tempoDano(0)
        {
            dano = 0;
            anim.addAnimacao("assets/objects/Torre.png", "DESATIVADO", 1, 0.4f, sf::Vector2f(1.5f, 1));
            anim.addAnimacao("assets/objects/Torre2.png", "ATIVADO", 1, 0.4f, sf::Vector2f(1.5f, 1));
		};
		~TorreEletrica() {};

        void Atualizar(float dt){
            tempoDano += dt;
            if(tempoDano >= 2000){
                if(dano)
                    dano = false;
                else
                    dano = true;
                
                tempoDano = 0;
            }
            AtualizarAnimacao();
        };

        void AtualizarAnimacao() {
            if (!dano)
                anim.atualizar(false, "DESATIVADO");
            else
                anim.atualizar(false, "ATIVADO");
        };
	};
}