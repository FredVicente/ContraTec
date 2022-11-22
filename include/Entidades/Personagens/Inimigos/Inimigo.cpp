#include "Inimigo.h"

using namespace Entidades;

Inimigo::Inimigo(Coord<int> dir, Coord<float> posicao, Coord<float> tamanho, Jogador* pJ, ID id)
: Personagem(posicao, tamanho, dir, id)
{
	player = pJ;
}