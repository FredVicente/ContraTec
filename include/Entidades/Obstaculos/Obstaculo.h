#pragma once
#include <Entidades/Entidade.h>
#include "Animador/Animacao.h"

using namespace Animador;

namespace Entidades {
	class Obstaculo : public Entidade {
    protected:
        bool dano;
		Animacao anim;
	public:
		Obstaculo(Coord<float> pos = Coord<float>(0.f, 0.f), Coord<float> tam = Coord<float>(50.0f, 50.0f), ID i = vazio) : Entidade(pos, tam, i), dano(false), anim(shape) {};
		~Obstaculo() {};

		bool getDano(){ return dano; };

		void Executar() {};
		void Atualizar(float dt) {};
	};
}