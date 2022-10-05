#include "Plataforma.h"

Plataforma::Plataforma(float x, float y, float tx, float ty) {
	posicao.x = x;
	posicao.y = y;
	tamanho.x = tx;
	tamanho.y = ty;
	plataforma = sf::RectangleShape(tamanho);
	plataforma.setPosition(x, y);
}