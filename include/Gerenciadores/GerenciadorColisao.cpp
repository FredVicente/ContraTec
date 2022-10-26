#include "GerenciadorColisao.h"

using namespace Gerenciadores;

void GerenciadorColisao::Colisoes() {
    // Lista que cont�m todas as entidades do jogo.
    std::list<Entidade*> l = Entidade::lista;
    // Entidades de compara��o.
    Entidade* e1;
    Entidade* e2;

    // Come�a o loop entre as entidades.
    iterador1 = l.begin();
    while (iterador1 != l.end()) {
        e1 = *iterador1;
        iterador1++;
        
        iterador2 = iterador1;

        while (iterador2 != l.end()) {
            Entidade* e2 = *iterador2;
            iterador2++;

            // Apenas testa se n�o s�o dois objetos do mesmo tipo.
            if (e1->id != e2->id) {
                // Dire��o de colis�o.
                int dir = TestaColisao(e1, e2);

                if (dir != NAO_COLIDINDO) {
                    // N�o precisa testar efeito de colis�o na plataforma, pois ela se manter� igual.
                    if (e1->id != plataforma)
                        e1->Colisao(e2, dir);
                    // Inverte a dire��o de colis�o do objeto.
                    if (dir % 2)
                        dir++;
                    else
                        dir--;
                    // Colisao do segundo objeto.
                    if (e2->id != plataforma)
                        e2->Colisao(e1, dir);
                }
            }
        }
    }
}

int GerenciadorColisao::TestaColisao(Entidade* e1, Entidade* e2) {
    // Essa fun�ao apenas testa se o objeto est� colidindo, o efeito da colisao � feito dentro da entidade.
    // A fun��o so retorna a dire��o de colis�o! Retorna 0 caso n�o esteja colidindo.

    // A interse��o � usada para saber em qual coordenada exatamente o objeto est� colidindo.
    Coord<float> intersecao;
    intersecao.x = e1->posicao.x + e1->tamanho.x - e2->posicao.x;
    intersecao.y = e1->posicao.y + e1->tamanho.y - e2->posicao.y;
    
    if (intersecao.x > e1->tamanho.x)
        intersecao.x = e1->tamanho.x;
    if (e1->posicao.x >= e2->posicao.x + e2->tamanho.x - e1->tamanho.x)
        intersecao.x = e2->posicao.x + e2->tamanho.x - e1->posicao.x;
    
    if (intersecao.y > e1->tamanho.y)
        intersecao.y = e1->tamanho.y;
    if (e1->posicao.y >= e2->posicao.y + e2->tamanho.y - e1->tamanho.y)
        intersecao.y = e2->posicao.y + e2->tamanho.y - e1->posicao.y;

    if (intersecao.x <= 0 || intersecao.y <= 0) { return 0; }

    if (intersecao.x > intersecao.y) {
        if (e1->posicao.y + e1->tamanho.y < e2->posicao.y + e2->tamanho.y / 2)
            return BAIXO;
        else
            return CIMA;
    }
    else {
        if (e1->posicao.x + e1->tamanho.x < e2->posicao.x + e2->tamanho.x / 2)
            return DIREITA;
        else
            return ESQUERDA;
    }

    return NAO_COLIDINDO;
}