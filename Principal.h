#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <Math/Coord.h>
#include <Listas/ListaEntidades.h>
#include <Gerenciadores/GerenciadorColisao.h>

using namespace Listas;
using namespace Gerenciadores;
using namespace Entidades;
using namespace Math;

class Principal
{
public:
	Principal() {};
	~Principal() {};
	void Executar();
};

