#pragma once

#include "Ente.h"
#include "Entidades/Plataforma.h"
#include "Entidades/Personagem.h"
#include "Entidades/Personagens/Inimigos/Bombeta.h"
#include "Entidades/Personagens/Inimigos/Torreta.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorColisao.h"
#include <fstream>
#include <iostream>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Listas;

namespace Fases {
	class Fase : public Ente {
	public:
		sf::Font font;
		sf::Text vidas;
		GerenciadorColisao gC;
		ListaEntidades* listaEntidadesEstaticas;
		ListaEntidades* listaEntidadesMoveis;
		static int faseAtual;
		Jogador* player;

		Fase();
		~Fase();

		void imprimir(sf::View* view, sf::RenderWindow* window);
		void virtual Atualizar(float dt) = 0;
		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);
		void criarFase(const char* path, Jogador* player, Coord<int> tamanho);
	};
}
