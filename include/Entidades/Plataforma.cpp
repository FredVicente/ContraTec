#include "Plataforma.h"

using namespace Entidades;

<<<<<<< Updated upstream
void Plataforma::Inicializa(Coord<float> pos, Coord<float> tam, sf::Color cor) {
	posicao = pos;
	tamanho = tam;
	shape = new sf::RectangleShape(sf::Vector2f(tamanho.x, tamanho.y));
=======
Plataforma::Plataforma(Coord<float> pos, Coord<float> tam) : 
	Entidade(pos, tam, plataforma) {
>>>>>>> Stashed changes
	shape->setFillColor(sf::Color::White);
	setPosicao(pos);
}