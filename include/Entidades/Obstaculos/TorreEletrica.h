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
			shape->setFillColor(sf::Color::Magenta);
		};
		~TorreEletrica() {};

        void Atualizar(float dt){
            tempoDano += dt;
            if(tempoDano >= 6000){
                if(dano){
                    dano = false;
                    shape->setFillColor(sf::Color::Blue);
                }
                else{
                    dano = true;
                    shape->setFillColor(sf::Color::Magenta);
                }
                
                tempoDano = 0;
            }
        };
	};
}