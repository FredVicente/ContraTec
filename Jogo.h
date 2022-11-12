#pragma once
#include <SFML/Graphics.hpp>
#include <Math/Coord.h>
#include <Entidades/Personagem.h>
#include <Entidades/Plataforma.h>
#include <Entidades/Personagens/Jogador.h>
#include <Gerenciadores/GerenciadorColisao.h>
#include <iostream>
#include <Fases/Fase1.h>
#include <Controles/ControleJogador.h>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Math;
using namespace Fases;

using namespace std;

class Jogo
{
private:
	Fase1 fase1;
public:
	Jogo() { Inicializar(); };
	~Jogo() {};
	void Inicializar();
};