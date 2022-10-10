#include "Objeto.h"

Objeto::Objeto(float x, float y, float tx, float ty) {
	posicao.x = x;
	posicao.y = y;
	tamanho.x = tx;
	tamanho.y = ty;
	shape = new sf::RectangleShape(tamanho);
	setPosicao(x, y);
}

void Objeto::setPosicao(float x, float y) {
	(*shape).setPosition(x, y);
}