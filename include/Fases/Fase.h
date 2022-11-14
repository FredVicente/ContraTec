#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"
#include "Gerenciadores/GerenciadorColisao.h"
<<<<<<< Updated upstream
#include <list>
=======
#include "Math/Coord.h"
#include <fstream>
#include <iostream>
>>>>>>> Stashed changes

using namespace Gerenciadores;
using namespace Entidades;
using namespace std;

namespace Fases {
	class Fase : public Ente {
	public:
		GerenciadorColisao gC;
<<<<<<< Updated upstream
		std::list<Entidade*> lista;
=======
		ListaEntidades *listaEntidadesEstaticas;
		ListaEntidades *listaEntidadesMoveis;
>>>>>>> Stashed changes

		Fase();
		~Fase() {};

		void virtual Executar() = 0;
<<<<<<< Updated upstream
=======

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);

		void criarFase(const char* path);
>>>>>>> Stashed changes
	};
}
