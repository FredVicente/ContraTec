#pragma once
#include <SFML/Graphics.hpp>

class Plataforma
{
private:
	sf::RectangleShape plataforma;

public:
	sf::Vector2f posicao;
	sf::Vector2f tamanho;
	Plataforma() {};
	Plataforma(float x, float y, float tx, float ty);
	~Plataforma() {};

	sf::RectangleShape getShape() { return plataforma; };
};

