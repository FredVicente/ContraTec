#pragma once
#include <SFML/Graphics.hpp>
#include <Math/Coord.h>
#include <Gerenciadores/GerenciadorGrafico.h>

using namespace Math;
using namespace Gerenciadores;

class Ente
{
protected:
	GerenciadorGrafico* gGrafico;
public:
	Ente() : gGrafico(gGrafico->getInstancia()){};
	~Ente() {};
	
	void virtual Executar() = 0;

	void imprimir() {};
};


