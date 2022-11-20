#include "Fase.h"

using namespace Fases;

int Fase::faseAtual = 1;

Fase::Fase() {
	player = nullptr;
	listaEntidadesMoveis = nullptr;
	listaEntidadesEstaticas = nullptr;
}

Fase::~Fase() {
	listaEntidadesMoveis->removerEntidade(player);
	if (listaEntidadesEstaticas)
		delete(listaEntidadesEstaticas);
	if (listaEntidadesMoveis)
		delete(listaEntidadesMoveis);
}

void Fase::imprimir(sf::View* view, sf::RenderWindow* window) {
	window->clear();

	int i = 0;
	Entidade* e;
	for (i = 0; i < listaEntidadesMoveis->getTamanho(); i++) {
		e = (*listaEntidadesMoveis)[i];
		window->draw(*e->getShape());
	}
	for (i = 0; i < listaEntidadesEstaticas->getTamanho(); i++) {
		e = (*listaEntidadesEstaticas)[i];
		window->draw(*e->getShape());
	}

	vidas.setString("Vidas: " + to_string(player->vidas));
	vidas.setPosition(view->getCenter() - sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));

	view->setCenter(player->getPosicao().x + player->getTamanho().x / 2, view->getCenter().y);

	window->draw(vidas);
	window->setView(*view);
	window->display();
}

Entidade* Fase::instanciaEntidade(Coord<float> pos, ID id) {
	switch (id) {
	case (plataforma): {
		Plataforma* p = new Plataforma(pos);
		return p;
	}
	default:
		break;
	}
	return nullptr;
}

void Fase::criarFase(const char* path, Jogador* player, Coord<int> tamanho) {
	ifstream file;
	char** fase = (char**) malloc(tamanho.y * sizeof(char*));

	int i, j;
	for (i = 0; i < tamanho.y; i++) {
		fase[i] = (char*)malloc(tamanho.x * sizeof(char));
	}

	file.open(path);

	if (!file) {
		cout << "ERROR: caminho invalido para fase!" << endl;
		exit(54);
	}

	while (!file.eof()) {
		for (i = 0; i < tamanho.y; i++) {
			for (j = 0; j < tamanho.x; j++) {
				file >> fase[i][j];

				if (fase[i][j] == 'P')
					listaEntidadesEstaticas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), plataforma));
				else if (fase[i][j] == 'J') {
					listaEntidadesMoveis->adicionarEntidade(player);
					player->setPosicao(Coord<float>(j * 50, i * 50));
					player->setPosicao(Coord<float>(j * 50, i * 50));
				}
			}
		}
	}

	for (i = 0; i < tamanho.y; i++) {
		free(fase[i]);
	}
	free(fase);

	file.close();
}