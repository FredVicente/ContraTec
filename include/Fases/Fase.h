#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"
#include "Entidades/Personagens/Inimigos/Bombeta.h"
#include "Entidades/Personagens/Inimigos/Torreta.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorColisao.h"
#include "Math/Coord.h"
#include <fstream>
#include <iostream>
#include "Math/Coord.h"

using namespace Gerenciadores;
using namespace Listas;
using namespace Entidades;
using namespace std;

namespace Fases {
	class Fase : public Ente {
	public:
		GerenciadorColisao gC;
		ListaEntidades *listaEntidadesEstaticas;
		ListaEntidades *listaEntidadesMoveis;
		ListaEntidades *listaEntidades;
		Jogador* player;

		Fase();
		~Fase() {};

		void virtual Executar() = 0;

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);

		void criarFase(const char* path);
	};
}
