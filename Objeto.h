#pragma once
#include <SFML/Graphics.hpp>

class Objeto
{
private:
	

public:
	sf::RectangleShape* shape;
	sf::Vector2f posicao;
	sf::Vector2f tamanho;
	
	Objeto() {};
	Objeto(float x, float y, float tx, float ty);
	~Objeto() {};

	void setPosicao(float x, float y);
};

