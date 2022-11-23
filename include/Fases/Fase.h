#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"
#include "Entidades/Personagens/Inimigos/Bombeta.h"
#include "Entidades/Personagens/Inimigos/Torreta.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorColisao.h"
#include "Gerenciadores/GerenciadorGrafico.h"
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
		ListaEntidades* listaEntidadesEstaticas;
		ListaEntidades* listaEntidadesMoveis;
		// Lista apenas para entidades de colisao.
		ListaEntidades* listaPlataformas;
		static int faseAtual;
		Jogador* player;
		float dT;

		Fase(Jogador* p = nullptr);
		~Fase();

		void Atualizar(float dt);
		virtual int PassarFase() = 0;
		void imprimir();

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);

		void criarFase(const char* path, Jogador* player, Coord<int> tamanho);
	};
}
