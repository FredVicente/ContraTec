#pragma once
#include <SFML/Graphics.hpp>
#include <Math/Coord.h>

using namespace Math;

class Ente
{
protected:
public:
	Ente() {};
	~Ente() {};

	void virtual executar() = 0;

	void imprimir() {};
};


