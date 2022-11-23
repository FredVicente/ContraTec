#pragma once
#include <SFML/Graphics.hpp>
#include <Math/Coord.h>

using namespace Math;

class Ente
{
public:
	Ente() {};
	~Ente() {};

	void virtual Executar() = 0;

	void imprimir() {};
};


