#pragma once
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Obstaculos/Elevador.h"
#include "Entidades/Obstaculos/TorreEletrica.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Personagens/Inimigos/Bombeta.h"
#include "Entidades/Personagens/Inimigos/Torreta.h"
#include "Entidades/Personagens/Inimigos/ReiRobo.h"
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
		string pathSave;
	public:
		GerenciadorColisao gC;
		ListaEntidades* listaEntidadesEstaticas;
		ListaEntidades* listaEntidadesMoveis;
		ListaEntidades* listaPlataformas;
		static int faseAtual;

		Fase(Jogador* p = nullptr, string path = "");
		~Fase();

		void Atualizar(float dt);
		virtual int PassarFase() = 0;
		void imprimir();

		bool chanceInimigo();

		Entidade* instanciaEntidade(Coord<float> pos, ID id = vazio);

		void criarFase(const char* path, Jogador* player, Coord<int> tamanho);

		void carregarFase();
	};
}
