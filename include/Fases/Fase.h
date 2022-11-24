#pragma once
#include "Entidades/Plataforma.h"
#include "Entidades/Personagens/Inimigos/Bombeta.h"
#include "Entidades/Personagens/Inimigos/Torreta.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorColisao.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Math/Coord.h"
#include <fstream>
#include <iostream>

using namespace Gerenciadores;
using namespace Listas;
using namespace Entidades;
using namespace std;

namespace Fases {
	class Fase : public Ente {
	protected:
		sf::Font fonte;
		sf::Text vidas;
		sf::Text pontos;
		Jogador* player;
		float dT;
		string pathSave;
	public:
		GerenciadorColisao gC;
		ListaEntidades* listaEntidadesEstaticas;
		ListaEntidades* listaEntidadesMoveis;
		// Lista apenas para entidades de colisao.
		ListaEntidades* listaPlataformas;

		static int faseAtual;

		Fase(Jogador* p, string);
		~Fase();

		void Atualizar(float dt);
		virtual int PassarFase() = 0;
		void imprimir();

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);

		void criarFase(const char* path, Jogador* player, Coord<int> tamanho);
	};
}
