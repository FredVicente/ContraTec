#include "GerenciadorColisao.h"
#include "Entidades/Entidade.h"

using namespace Gerenciadores;

void GerenciadorColisao::Colisoes(std::list<Entidade*> l) {
    // Entidades de comparação.
    Entidade* e1;
    Entidade* e2;

    // ComeÃ§a o loop entre as entidades.
    iterador1 = l.begin();
    while (iterador1 != l.end()) {
        e1 = *iterador1;
        iterador1++;
        
        iterador2 = iterador1;

        while (iterador2 != l.end()) {
            Entidade* e2 = *iterador2;
            iterador2++;

            // Apenas testa se não são dois objetos do mesmo tipo.
            if (e1->getID() != e2->getID()) {
                // Direção de colisão.
                int dir = TestaColisao(e1, e2);

                if (dir != NAO_COLIDINDO) {
                    // Não precisa testar efeito de colisão na plataforma, pois ela se manterá igual.
                    if (e1->getID() != plataforma)
                        e1->Colisao(e2, dir);
                    // Inverte a direÃ§Ã£o de colisÃ£o do objeto.
                    if (dir % 2)
                        dir++;
                    else
                        dir--;
                    // Colisao do segundo objeto.
                    if (e2->getID() != plataforma)
                        e2->Colisao(e1, dir);
                }
            }
        }
    }
}

int GerenciadorColisao::TestaColisao(Entidade* e1, Entidade* e2) {
    // Essa funÃ§ao apenas testa se o objeto estÃ¡ colidindo, o efeito da colisao Ã© feito dentro da entidade.
    // A funÃ§Ã£o so retorna a direÃ§Ã£o de colisÃ£o! Retorna 0 caso nÃ£o esteja colidindo.

    // A interseÃ§Ã£o Ã© usada para saber em qual coordenada exatamente o objeto estÃ¡ colidindo.
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