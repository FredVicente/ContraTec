#include "GerenciadorColisao.h"

using namespace Gerenciadores;

void GerenciadorColisao::Colisao() {
    std::list<Entidade*> l = Entidade::lista;
    iterador1 = l.begin();
    while (iterador1 != l.end()) {
        Entidade* entidade1 = *iterador1;
        
        if (entidade1->id != plataforma){
            iterador2 = iterador1;
            iterador2++;
            entidade1->colisao.x = false;
            entidade1->colisao.y = false;

            while (iterador2 != l.end()) {
                Entidade* entidade2 = *iterador2;
                iterador2++;

                if (entidade1->posicao.x + entidade1->tamanho.x > entidade2->posicao.x && entidade1->posicao.x < entidade2->posicao.x + entidade2->tamanho.x) {
                    if (entidade1->posicao.y + entidade1->tamanho.y > entidade2->posicao.y && entidade1->posicao.y + entidade1->tamanho.y < entidade2->posicao.y + entidade2->tamanho.y / 2) {
                        entidade1->posicao.y = entidade2->posicao.y - entidade1->tamanho.y;
                        entidade1->colisao.y = true;
                    }
                    else if (entidade1->posicao.y < entidade2->posicao.y + entidade2->tamanho.y && entidade1->posicao.y > entidade2->posicao.y + entidade2->tamanho.y / 2) {
                        entidade1->posicao.y = entidade2->posicao.y + entidade2->tamanho.y;
                        entidade1->colisao.y = true;
                    }
                }
                if (entidade1->posicao.y + entidade1->tamanho.y > entidade2->posicao.y && entidade1->posicao.y < entidade2->posicao.y + entidade2->tamanho.y) {
                    if (entidade1->posicao.x + entidade1->tamanho.x > entidade2->posicao.x && entidade1->posicao.x + entidade1->tamanho.x < entidade2->posicao.x + entidade2->tamanho.x / 2) {
                        entidade1->posicao.x = entidade2->posicao.x - entidade1->tamanho.x;
                        entidade1->colisao.x = true;
                    }
                    else if (entidade1->posicao.x < entidade2->posicao.x + entidade2->tamanho.x && entidade1->posicao.x > entidade2->posicao.x + entidade2->tamanho.x / 2) {
                        entidade1->posicao.x = entidade2->posicao.x + entidade2->tamanho.x;
                        entidade1->colisao.x = true;
                    }
                }
            }
        }
        iterador1++;
    }
}
