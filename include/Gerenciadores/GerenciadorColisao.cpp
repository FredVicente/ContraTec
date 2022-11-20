#include "GerenciadorColisao.h"
#include "Entidades/Entidade.h"

using namespace Gerenciadores;

void GerenciadorColisao::colisoes() {
    // Entidades de compara��o.
    int i = 0, j;
    Entidade* e1;
    Entidade* e2;

    // Come�a o loop entre as entidades moveis e est�ticas.
    while (i < listaMoveis->getTamanho()) {
        e1 = (*listaMoveis)[i];
        i++;
        j = i;
        while (j < listaEstatica->getTamanho()) {
            e2 = (*listaEstatica)[j];
            j++;
            // Dire��o de colis�o.
            int dir = testaColisao(e1, e2);

            if (dir != NAO_COLIDINDO) {
                e1->colisao(e2, dir);
            }
        }
    }
    i = 0;
    // Come�a o loop entre as entidades m�veis.
    while (i < listaMoveis->getTamanho() - 1) {
        e1 = (*listaMoveis)[i];
        i++;
        j = i;
        while (j < listaMoveis->getTamanho()) {
            e2 = (*listaMoveis)[j];
            j++;
            // Dire��o de colis�o.
            int dir = testaColisao(e1, e2);

            if (dir != NAO_COLIDINDO) {
                e1->colisao(e2, dir);
                // Inverte a dire��o de colis�o do objeto.
                if (dir % 2)
                    dir++;
                else
                    dir--;
                // Colisao do segundo objeto.
                e2->colisao(e1, dir);
            }
        }
    }
}

int GerenciadorColisao::testaColisao(Entidade* e1, Entidade* e2) {
    // Essa fun�ao apenas testa se o objeto est� colidindo, o efeito da colisao � feito dentro da entidade.
    // A fun��o so retorna a dire��o de colis�o! Retorna 0 caso n�o esteja colidindo.

    // A interse��o � usada para saber em qual coordenada exatamente o objeto est� colidindo.
    Coord<float> intersecao;
    intersecao.x = e1->getPosicao().x + e1->getTamanho().x - e2->getPosicao().x;
    intersecao.y = e1->getPosicao().y + e1->getTamanho().y - e2->getPosicao().y;
    
    if (intersecao.x > e1->getTamanho().x)
        intersecao.x = e1->getTamanho().x;
    if (e1->getPosicao().x >= e2->getPosicao().x + e2->getTamanho().x - e1->getTamanho().x)
        intersecao.x = e2->getPosicao().x + e2->getTamanho().x - e1->getPosicao().x;
    
    if (intersecao.y > e1->getTamanho().y)
        intersecao.y = e1->getTamanho().y;
    if (e1->getPosicao().y >= e2->getPosicao().y + e2->getTamanho().y - e1->getTamanho().y)
        intersecao.y = e2->getPosicao().y + e2->getTamanho().y - e1->getPosicao().y;

    if (intersecao.x <= 0 || intersecao.y <= 0) { return 0; }

    if (intersecao.x > intersecao.y) {
        if (e1->getPosicao().y + e1->getTamanho().y < e2->getPosicao().y + e2->getTamanho().y / 2)
            return BAIXO;
        else
            return CIMA;
    }
    else {
        if (e1->getPosicao().x + e1->getTamanho().x < e2->getPosicao().x + e2->getTamanho().x / 2)
            return DIREITA;
        else
            return ESQUERDA;
    }

    return NAO_COLIDINDO;
}

void GerenciadorColisao::setLista(ListaEntidades* lM, ListaEntidades* lE) {
    listaMoveis = lM;
    listaEstatica = lE;
}