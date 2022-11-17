#include "Personagem.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

Personagem::Personagem(Coord<float> posicao, Coord<float> tamanho, ID id) : Entidade(posicao, tamanho, id) {
	velocidade = Coord<float>(0, 0);
	aceleracao = Coord<float>(0, 1);
	getShape()->setFillColor(sf::Color::Green);
}

void Personagem::mover() {
	velocidade += aceleracao;
	Coord<float> pos = getPosicao();
	setPosicao(pos + velocidade);
}

void Personagem::colisao(Entidade* e, int dir) {
	int id = e->getID();
	if (id == inimigo) {
		// Implementar com inimigo.
	}

	Coord<float> p1 = getPosicao();
	Coord<float> p2 = e->getPosicao();
	Coord<float> t1 = getTamanho();
	Coord<float> t2 = e->getTamanho();
	if (id == plataforma) {
		if (dir == DIREITA) {
			setPosicao(Coord<float>(p2.x - t1.x, p1.y));
			velocidade.x = 0;
		}
		else if (dir == ESQUERDA) {
			setPosicao(Coord<float>(p2.x + t2.x, p1.y));
			velocidade.x = 0;
		}
		if (dir == BAIXO) {
			setPosicao(Coord<float>(p1.x, p2.y - t1.y));
			velocidade.y = 0;
			pulo = true;
		}
		else if (dir == CIMA) {
			setPosicao(Coord<float>(p1.x, p2.y + t2.y));
			velocidade.y = 0;
		}
	}
}
