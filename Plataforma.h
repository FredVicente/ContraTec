#pragma once
#include <SFML/Graphics.hpp>
#include "Objeto.h"

class Plataforma : public Objeto
{
private:

public:
	Plataforma() {};
	Plataforma(float x, float y, float tx, float ty) : Objeto(x, y, tx, ty) {};
	~Plataforma() {};
};

