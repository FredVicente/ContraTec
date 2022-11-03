#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <Math/Coord.h>
#include <Entidades/Personagem.h>
#include <Entidades/Plataforma.h>
#include <Gerenciadores/GerenciadorColisao.h>
#include <Fases/Fase1.h>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Math;
using namespace Fases;

class Principal
{
private:
	Fase1 fase1;
public:
	Principal() { Inicializar(); };
	~Principal() {};
	void Inicializar();
};

