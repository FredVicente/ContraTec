#include "Fase.h"

using namespace Fases;

int Fase::faseAtual = 1;

Fase::Fase(Jogador* p) {
	listaEntidadesEstaticas = new ListaEntidades;
	listaEntidadesMoveis = new ListaEntidades;
	player = p;
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

	vidas.setString("Vidas: " + to_string(player->getVidas()));
	vidas.setPosition(view->getCenter() - sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));

	view->setCenter(player->getPosicao().x + player->getTamanho().x / 2, view->getCenter().y);

	sf::Font fonte;
	fonte.loadFromFile("Fonts/PixelFont2.ttf");

	sf::Text t;
	t.setFont(fonte);
	t.setCharacterSize(30);
	t.setPosition(800, 200);

	if (player->pontos < (int)player->getPosicao().x)
		player->pontos = (int)player->getPosicao().x;
	t.setString("Pontos: " + to_string(player->pontos));
	window->draw(t);

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
	case (bombeta):{
		Bombeta* b = new Bombeta(Coord<int>(-1,0), pos, player);
		return b;
	}
	case(torreta):{
		Torreta* t = new Torreta(Coord<int>(-1,0), pos, player);
		t->setFase(this);
		return t;
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
				}
				else if (fase[i][j] == 'P')
					listaEntidadesEstaticas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), plataforma));
				else if(fase[i][j] == 'B')
					listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), bombeta));
				else if(fase[i][j] == 'T')
					listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), torreta));
			}
		}
	}

	for (i = 0; i < tamanho.y; i++)
		free(fase[i]);
	free(fase);

	file.close();
}