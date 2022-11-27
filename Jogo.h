#pragma once
#include <SFML/Graphics.hpp>
#include <Math/Coord.h>
#include <Entidades/Obstaculos/Plataforma.h>
#include <Entidades/Personagens/Jogador.h>
#include <Gerenciadores/GerenciadorColisao.h>
#include <Gerenciadores/GerenciadorGrafico.h>
#include <Menus/MenuFase.h>
#include <Menus/MenuPause.h>
#include <Menus/MenuPrincipal.h>
#include <Menus/MenuNomeJogador.h>
#include <Menus/MenuRanking.h>
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
	State state;

	Menu* pMenuAtual;
	Menu* pMenuPrincipal;
	Menu* pMenuPause;
	Menu* pMenuFase;
	Menu* pMenuNomeJogador;
	Menu* pMenuRanking;

	Fase1* fase1;
	Fase2* fase2;
	Fase* pFaseAtual;
	Jogador* jogador;
	GerenciadorGrafico* gGrafico;
public:
	Jogo();
	~Jogo() {};

	void Inicializar();

	void setFase(int fase, string path = "");

	void SalvarFase();
	void CarregarFase();
	void SalvarRanking();
	void CarregarRanking();
};