#include "GerenciadorColisao.h"
#include "Entidades/Personagens/Jogador.h"
#include "Fases/Fase.h"

using namespace Gerenciadores;
using namespace Fases;

void GerenciadorColisao::setLista(ListaEntidades* lE, ListaEntidades* lM) {
    listaEstatica = lE;
    listaMoveis = lM;
}

void GerenciadorColisao::Colisoes() {
    // Entidades de compara��o.
    int i = 0, j;
    Entidade* e1;
    Entidade* e2;

    // Come�a o loop entre as entidades moveis e est�ticas.
    while (i < listaMoveis->getTamanho()) {
        e1 = (*listaMoveis)[i];
        i++;
        j = i;
        if (e1->estaAtivo() && e1->getRange()){
            while (j < listaEstatica->getTamanho()) {
                e2 = (*listaEstatica)[j];
                j++;

                if (e2->getRange()) {
                    // Dire��o de colis�o.
                    int dir = TestaColisao(e1, e2);

                    if (dir != NAO_COLIDINDO) {
                        int id1 = e1->getID();
                        int id2 = e2->getID();
                        if ((id1 == bombeta || id1 == torreta || id1 == reiRobo || id1 == jogador)) {
                            ColisaoPersonagemObstaculo(e1, e2, dir);
                        }
                        else if (id1 == projetil) {
                            ColisaoProjetilObstaculo(e1);
                        }
                    }
                }
            }
        }
    }

    i = 0;
    // Come�a o loop entre as entidades m�veis.
    while (i < listaMoveis->getTamanho() - 1) {
        e1 = (*listaMoveis)[i];
        i++;
        j = i;
        if(e1->estaAtivo() && e1->getRange()){
            while (j < listaMoveis->getTamanho()) {
                e2 = (*listaMoveis)[j];
                j++;
                // Dire��o de colis�o.
                if (e2->estaAtivo() && e2->getRange()) {
                    int dir = TestaColisao(e1, e2);

                    if (dir != NAO_COLIDINDO) {
                        int id1 = e1->getID();
                        int id2 = e2->getID();

                        if (((id1 == jogador) || (id2 == jogador)) && ((id1 == torreta || id1 == bombeta || id1 == reiRobo) || (id2 == torreta || id2 == bombeta || id2 == reiRobo))) {
                            ColisaoJogadorInimigo(e1, e2);
                        }
                        if ((id1 == jogador || id2 == jogador) && (id1 == projetil || id2 == projetil)) {
                            ColisaoJogadorProjetil(e1, e2);
                        }
                        if (((id1 == bombeta || id1 == torreta || id1 == reiRobo) || (id2 == bombeta || id2 == torreta || id2 == reiRobo)) && (id1 == projetil || id2 == projetil)) {
                            ColisaoInimigoProjetil(e1, e2);
                        }
                    }
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

void GerenciadorColisao::ColisaoJogadorInimigo(Entidade* e1, Entidade* e2){
    int id1 = e1->getID();
    Jogador* per;

    if((id1 == jogador))
        per = dynamic_cast<Jogador*>(e1);
    else
        per = dynamic_cast<Jogador*>(e2);
    
    per->receberDano();
}
void GerenciadorColisao::ColisaoJogadorProjetil(Entidade* e1, Entidade* e2){
    int id1 = e1->getID();
    Jogador* jog;
    Projetil* proj;

    if((id1 == jogador)){
        jog = dynamic_cast<Jogador*>(e1);
        proj = dynamic_cast<Projetil*>(e2);
    }
    else{
        jog = dynamic_cast<Jogador*>(e2);
        proj = dynamic_cast<Projetil*>(e1);
    }

    if(proj->estaAtivo() && proj->getAtirador() != jogador){
        jog->receberDano();
        proj->setEstado(false);
    }
}
void GerenciadorColisao::ColisaoInimigoProjetil(Entidade* e1, Entidade* e2){
    int id1 = e1->getID();
    Personagem* per = nullptr;
    Projetil* proj = nullptr;

    if((id1 == torreta || id1 == bombeta || id1 == reiRobo)){
        per = dynamic_cast<Personagem*>(e1);
        proj = dynamic_cast<Projetil*>(e2);
    }
    else{
        per = dynamic_cast<Personagem*>(e2);
        proj = dynamic_cast<Projetil*>(e1);
    }
    
    if(proj->estaAtivo() && proj->getAtirador() == jogador){
        per->receberDano();
        proj->setEstado(false);
    }
}
void GerenciadorColisao::ColisaoPersonagemObstaculo(Entidade* e1, Entidade* e2, int dir){

    Personagem* per = dynamic_cast<Personagem*>(e1);
    Obstaculo* obs = dynamic_cast<Obstaculo*>(e2);
    Jogador* jog = nullptr;
    Coord<float> p1 = e1->getPosicao();
    Coord<float> p2 = e2->getPosicao();
    Coord<float> t1 = e1->getTamanho();
    Coord<float> t2 = e2->getTamanho();

    if(per->getID() == jogador){
        jog = dynamic_cast<Jogador*>(per);
        if(dir == BAIXO)
            jog->setPulo(true);
        if(obs->getDano())
            jog->receberDano();
    }

    if((jog && obs->getID() == torreEletrica) && (jog->getInvencivel() || !obs->getDano())){}
    else{
        if (dir == DIREITA) {
            per->setPosicao(Coord<float>(p2.x - t1.x, p1.y));
            per->setVelocidade("x", 0);
        }
        else if (dir == ESQUERDA) {
            per->setPosicao(Coord<float>(p2.x + t2.x, p1.y));
            per->setVelocidade("x", 0);
        }
        if (dir == BAIXO) {
            per->setPosicao(Coord<float>(p1.x, p2.y - t1.y));
            per->setVelocidade("y", 0);
        }
        else if (dir == CIMA) {
            per->setPosicao(Coord<float>(p1.x, p2.y + t2.y));
            per->setVelocidade("y", 0);
        }
    }
}
void GerenciadorColisao::ColisaoProjetilObstaculo(Entidade* e1) {
    e1->setEstado(false);
}