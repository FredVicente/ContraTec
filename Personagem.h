#pragma once
#include <SFML/Graphics.hpp>
#include "Objeto.h"

class Personagem : public Objeto
{
private:

public:
	sf::Vector2f velocidade;
	sf::Vector2f aceleracao;
	bool pulo = false;

	Personagem() {};
	Personagem(float x, float y, float tx, float ty);
	~Personagem() {};

	void Mover();
};

