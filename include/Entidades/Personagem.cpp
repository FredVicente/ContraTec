#include "Personagem.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;
using namespace Listas;

namespace Entidades{

	namespace Personagens{

		Personagem::Personagem(ID id, Coord<float> posicao, Coord<float> tamanho) : Entidade(id, posicao, tamanho) {
			velocidade = Coord<float>(0, 0);
			aceleracao = Coord<float>(0, 0.001f);
			shape->setFillColor(sf::Color::Green);
		}

		void Personagem::Mover() {
			velocidade += aceleracao;
			posicao += velocidade;
			setPosicao(posicao);
		}

		void Personagem::Colisao(Entidade* e, int dir) {
			if (e->getID() == inimigo) {
				// Implementar depois
			}

			Coord<float> p1 = getPosicao();
			Coord<float> p2 = e->getPosicao();
			Coord<float> t1 = getTamanho();
			Coord<float> t2 = e->getTamanho();

			if(e->getID() == plataforma){
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

	}

}