#pragma once
#include <SFML/Graphics.hpp>
#include <Math/Coord.h>
#include <Menu.h>
#include <Entidades/Personagem.h>
#include <Entidades/Plataforma.h>
#include <Entidades/Personagens/Jogador.h>
#include <Gerenciadores/GerenciadorColisao.h>
#include <Gerenciadores/GerenciadorGrafico.h>
#include <iostream>
#include <Fases/Fase1.h>
#include <Controles/ControleJogador.h>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Math;
using namespace Fases;

using namespace std;

enum State {
	pause = 0,
	playing
};

class Jogo
{
private:
	GerenciadorGrafico* pGrafico;
	State state;
	Menu menu;
	Fase1 fase1;
	Jogador* jogador;
public:
	Jogo() {
		Inicializar();
	};
	~Jogo() {};
	void Inicializar();
};