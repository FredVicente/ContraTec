#pragma once
#include "Obstaculo.h"

namespace Entidades {
	class Elevador : public Obstaculo {
    private:
        int alturaMinima;
        int alturaMaxima;
        int largura;
        int direcaoMudancaDeAltura;
	public:
		Elevador(Coord<float> pos = Coord<float>(0.f, 0.f), int altMax = 100, int altMin = 30, int larg = 50) :
        largura(larg),
        alturaMaxima(altMax),
        alturaMinima(altMin),
        direcaoMudancaDeAltura(1),
		Obstaculo(pos, Coord<float>(larg, altMin), elevador) {
            //sprite = new Imagem("assets/elevator.png", 8, 1, sf::Vector2f(50, 50), sf::Vector2f(0, 0), sf::Vector2f(1, 1));
		};
		~Elevador() {};

        void Atualizar(float dt) {
            if(tamanho.y > alturaMaxima || tamanho.y < alturaMinima)
                direcaoMudancaDeAltura *= -1;
            mudarAltura();
        };

        void mudarAltura(){
            setTamanho(Coord<float>(tamanho.x, tamanho.y + direcaoMudancaDeAltura));
            setPosicao(Coord<float>(posicao.x, posicao.y - direcaoMudancaDeAltura));
        }
	};
}