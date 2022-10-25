#include "Personagem.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

Personagem::Personagem(Coord<float> posicao, Coord<float> tamanho) : Entidade(posicao, tamanho, jogador) {
	velocidade = Coord<float>(0, 0);
	aceleracao = Coord<float>(0, 0.001f);
	shape->setFillColor(sf::Color::Green);
}

void Personagem::Mover() {
	velocidade += aceleracao;
	posicao += velocidade;

	if (colisao.x)
		velocidade.x = 0;
	if (colisao.y)
		velocidade.y = 0;

	setPosicao(posicao);
}
