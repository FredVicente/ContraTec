#include "Personagem.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

Personagem::Personagem(Coord<float> posicao, Coord<float> tamanho, ID id) : Entidade(posicao, tamanho, id) {
	velocidade = Coord<float>(0, 0);
	aceleracao = Coord<float>(0, 0.5f);
	getShape()->setFillColor(sf::Color::Green);
}

void Personagem::mover() {
	velocidade += aceleracao;
	Coord<float> pos = getPosicao();
	setPosicao(pos + velocidade);
}
