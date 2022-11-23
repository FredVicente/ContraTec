#pragma once
#include <SFML/Graphics.hpp>
#include <Math/Coord.h>
#include <Entidades/Personagens/Jogador.h>
#include <iostream>
#include <Fases/Fase1.h>
#include <Fases/Fase2.h>
#include <Menu.h>
#include <vector>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Math;
using namespace Fases;
using namespace std;

enum State {
	menu = 0,
	pause,
	playing
};

class Jogo
{
private:
	int faseAtual = 0;
	int menuAtual = 0;
	State state;
	Menu* menu;
	Menu* pauseMenu;
	Fase1* fase1;
	Fase2* fase2;
	Fase* pFaseAtual;
	Jogador jogador;
	GerenciadorGrafico* gGrafico;
public:
	Jogo();
	~Jogo() {};

	void Inicializar();

	void salvar();
	void carregar();
};