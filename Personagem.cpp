#include "Personagem.h"

Personagem::Personagem(float x, float y, float tx, float ty) : Objeto(x, y, tx, ty) {
	velocidade.x = 0; velocidade.y = 0; 
	aceleracao.x = 0; aceleracao.y = 0.001f;
	shape->setFillColor(sf::Color::Green);
}

void Personagem::Mover() {

	posicao.x += velocidade.x;
	posicao.y += velocidade.y;

	velocidade.x += aceleracao.x;
	velocidade.y += aceleracao.y;
}
