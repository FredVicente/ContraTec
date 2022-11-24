#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"
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

<<<<<<< Updated upstream
		Fase();
		~Fase() {};
=======
		Fase(Jogador* p, string pathS = "");
		~Fase();
>>>>>>> Stashed changes

		void virtual Executar() = 0;

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);

<<<<<<< Updated upstream
		void criarFase(const char* path);
=======
		void criarFase(const char* path, Jogador* player, Coord<int> tamanho);
		void carregarFase(Jogador* player);
		bool chanceInimigo();
>>>>>>> Stashed changes
	};
}
