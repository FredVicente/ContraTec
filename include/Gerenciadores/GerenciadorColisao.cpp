#include "GerenciadorColisao.h"
#include "Entidades/Personagens/Jogador.h"

using namespace Gerenciadores;

void GerenciadorColisao::colisoes() {
    // Entidades de compara��o.
    int i = 0, j;
    Entidade* e1;
    Entidade* e2;

    // Come�a o loop entre as entidades moveis e est�ticas.
    while (i < listaMoveis.getTamanho()) {
        e1 = (*listaEstatica)[i];
        i++;
        j = i;
        while (j < listaEstatica.getTamanho()) {
            e2 = (*listaEstatica)[j];
            j++;
            // Dire��o de colis�o.
            int dir = TestaColisao(e1, e2);

            if (dir != NAO_COLIDINDO) {
                int id1 = e1->getID();
                int id2 = e2->getID();
                if(((id1 == bombeta || id1 == torreta || id1 == jogador) || (id2 == bombeta || id2 == torreta || id2 == jogador)) && (id1 == plataforma || id2 == plataforma)){
                    ColisaoPersonagemPlataforma(e1, e2, dir);
                }
            }
        }
    }

    i = 0;
    // Come�a o loop entre as entidades m�veis.
    while (i < listaMoveis.getTamanho() - 1) {
        e1 = (*listaEstatica)[i];
        i++;
        j = i;
        while (j < listaMoveis.getTamanho()) {
            e2 = (*listaMoveis)[j];
            j++;
            // Dire��o de colis�o.
            if(e1->getEstado() && e2->getEstado()){
                int dir = TestaColisao(e1, e2);

                if (dir != NAO_COLIDINDO) {
                    int id1 = e1->getID();
                    int id2 = e2->getID();

                    if(((id1 == jogador) || (id2 == jogador)) && ((id1 == torreta || id1 == bombeta) || (id2 == torreta || id2 == bombeta))){
                        ColisaoJogadorInimigo(e1, e2);
                    }
                    if((id1 == jogador || id2 == jogador) && (id1 == projetil || id2 == projetil)){
                        ColisaoJogadorProjetil(e1, e2);
                    }
                    if(((id1 == bombeta || id1 == torreta) || (id2 == bombeta || id2 == torreta)) && (id1 == projetil || id2 == projetil)){
                        ColisaoInimigoProjetil(e1, e2);
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

    if((id1 == jogador)){
        Personagem* per = dynamic_cast<Personagem*>(e1);
        per->receberDano();
    }
    else{
        Personagem* per = dynamic_cast<Personagem*>(e2);
        per->receberDano();
    }
}
void GerenciadorColisao::ColisaoJogadorProjetil(Entidade* e1, Entidade* e2){
    int id1 = e1->getID();
    Personagem* per;
    Projetil* proj;

    if((id1 == jogador)){
        per = dynamic_cast<Personagem*>(e1);
        proj = dynamic_cast<Projetil*>(e2);
    }
    else{
        per = dynamic_cast<Personagem*>(e2);
        proj = dynamic_cast<Projetil*>(e1);
    }

    if(proj->getEstado() && proj->getAtirador() != jogador){
        per->receberDano();
        proj->setEstado(false);
    }
}
void GerenciadorColisao::ColisaoInimigoProjetil(Entidade* e1, Entidade* e2){
    int id1 = e1->getID();
    Personagem* per;
    Projetil* proj;

    if((id1 == torreta || id1 == bombeta)){
        per = dynamic_cast<Personagem*>(e1);
        proj = dynamic_cast<Projetil*>(e2);
    }
    else{
        per = dynamic_cast<Personagem*>(e2);
        proj = dynamic_cast<Projetil*>(e1);
    }
    
    if(proj->getEstado() && proj->getAtirador() == jogador){
        per->receberDano();
        proj->setEstado(false);
    }
}
void GerenciadorColisao::ColisaoPersonagemPlataforma(Entidade* e1, Entidade* e2, int dir){
    Personagem* per;
    int id2 = e2->getID();
    Coord<float> p1;
	Coord<float> p2;
	Coord<float> t1;
	Coord<float> t2;

    if((id2 == plataforma)){
        per = dynamic_cast<Personagem*>(e1);
        p1 = e1->getPosicao();
        p2 = e2->getPosicao();
        t1 = e1->getTamanho();
        t2 = e2->getTamanho();
    }
    else{
        per = dynamic_cast<Personagem*>(e2);
        p1 = e2->getPosicao();
        p2 = e1->getPosicao();
        t1 = e2->getTamanho();
        t2 = e1->getTamanho();
    }
	
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
        if(per->getID() == jogador){
            Jogador* jog = dynamic_cast<Jogador*>(per);
            jog->setPulo(true);
        }

	}
	else if (dir == CIMA) {
		per->setPosicao(Coord<float>(p1.x, p2.y + t2.y));
		per->setVelocidade("y", 0);
	}
}
