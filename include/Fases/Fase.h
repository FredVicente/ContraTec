#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagens/Jogador.h"
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
		sf::Font font;
		sf::Text vidas;
		GerenciadorColisao gC;
		ListaEntidades *listaEntidadesEstaticas;
		ListaEntidades *listaEntidadesMoveis;
		static int faseAtual;
		Jogador* player;

		Fase();
		~Fase() {};

		void clear();
		void virtual executar() = 0;
		void virtual atualizar(sf::View* view, sf::RenderWindow* window) = 0;

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);

		void criarFase(const char* path, Jogador* player, Coord<int> tamanho);
	};
}
