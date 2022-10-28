#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <Math/Coord.h>
#include <Listas/ListaEntidades.h>
#include <Entidades/Personagem.h>
#include <Entidades/Plataforma.h>
#include <Gerenciadores/GerenciadorColisao.h>
#include <Personagens/Jogador.h>
#include <iostream>

using namespace Listas;
using namespace Gerenciadores;
using namespace Entidades;
using namespace Math;

using namespace std;

class Principal
{
public:
	Principal() {};
	~Principal() {};
	void Executar();
};

