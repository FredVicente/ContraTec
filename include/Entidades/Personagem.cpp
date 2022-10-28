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
			if (e->id == inimigo) {
				// Implementar depois
			}

			if(e->id == plataforma){
				if (dir == DIREITA) {
					posicao.x = e->posicao.x - tamanho.x;
					velocidade.x = 0;
				}
				else if (dir == ESQUERDA) {
					posicao.x = e->posicao.x + e->tamanho.x;
					velocidade.x = 0;
				}
				if (dir == BAIXO) {
					posicao.y = e->posicao.y - tamanho.y;
					velocidade.y = 0;
					pulo = true;
				}
				else if (dir == CIMA) {
					posicao.y = e->posicao.y + e->tamanho.y;
					velocidade.y = 0;
				}
			}
		}

	}

}