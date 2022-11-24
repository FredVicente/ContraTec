#include "Fase.h"

using namespace Fases;

<<<<<<< Updated upstream
Fase::Fase() {
	listaEntidadesMoveis = nullptr;
	listaEntidadesEstaticas = nullptr;
=======
int Fase::faseAtual = 1;

Fase::Fase(Jogador* p, string pathS) {
	dT = 0;
	listaEntidadesEstaticas = new ListaEntidades;
	listaEntidadesMoveis = new ListaEntidades;
	listaPlataformas = new ListaEntidades;
	player = p;
	player->setFase(this);
	pathSave = pathS;

	fonte.loadFromFile("Fonts/PixelFont2.ttf");
	vidas.setFont(fonte);
	vidas.setCharacterSize(30);
	pontos.setFont(fonte);
	pontos.setCharacterSize(30);
}

Fase::~Fase() {
	listaEntidadesMoveis->removerEntidade(player);
	if (listaEntidadesEstaticas)
		delete(listaEntidadesEstaticas);
	if (listaEntidadesMoveis)
		delete(listaEntidadesMoveis);
	if (listaPlataformas)
		delete(listaPlataformas);
}

void Fase::Atualizar(float dt) {
	listaEntidadesMoveis->atualizaTodos(dt);
	listaEntidadesEstaticas->atualizaTodos(dt);
	listaPlataformas->atualizaTodos(dt);
	Fase::faseAtual += PassarFase();

	gC.Colisoes();

	imprimir();
}

void Fase::imprimir() {
	sf::RenderWindow* window = gGrafico->getJanela();
	sf::View* view = gGrafico->getView();

	vidas.setString("Vidas: " + to_string(player->getVidas()));
	vidas.setPosition(view->getCenter() - sf::Vector2f(window->getSize().x / 2 - 10, window->getSize().y / 2 - 20));

	pontos.setString("Pontos: " + to_string((int)player->pontos));
	pontos.setPosition(view->getCenter() - sf::Vector2f(window->getSize().x / 2 - 10, window->getSize().y / 2 - 70));

	view->setCenter(player->getPosicao().x + player->getTamanho().x / 2, view->getCenter().y);

	window->draw(pontos);
	window->draw(vidas);
	
	window->setView(*view);
	window->display();
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void Fase::criarFase(const char* path) {
	ifstream file;
	const int y = 13, x = 30;
	char fase[y][x];
=======
void Fase::criarFase(const char* path, Jogador* player, Coord<int> tamanho) {
	ifstream fileLevel;
	char** fase = (char**) malloc(tamanho.y * sizeof(char*));

	srand(time(NULL));

	int i, j;
	for (i = 0; i < tamanho.y; i++) {
		fase[i] = (char*)malloc(tamanho.x * sizeof(char));
	}
>>>>>>> Stashed changes

	file.open(path);

	if (!file) {
		cout << "ERROR: caminho invalido para fase!" << endl;
		exit(54);
	}

	int i, j;
	while (!file.eof()) {
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				file >> fase[i][j];

				if (fase[i][j] == 'P')
					listaEntidadesEstaticas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), plataforma));
<<<<<<< Updated upstream
=======
				if (pathSave == "") {
					if (fase[i][j] == 'J') {
						listaEntidadesMoveis->adicionarEntidade(player);
						player->setPosicao(Coord<float>(j * 50, i * 50));
					}
					else if (fase[i][j] == 'B')
						listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), bombeta));
					else if (fase[i][j] == 'b' && chanceInimigo())
						listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), bombeta));
					else if (fase[i][j] == 'T')
						listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), torreta));
					else if (fase[i][j] == 't' && chanceInimigo())
						listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), torreta));
				}
>>>>>>> Stashed changes
			}
		}
	}

<<<<<<< Updated upstream
	file.close();
=======
	if (pathSave != "")
		carregarFase(player);

	for (i = 0; i < tamanho.y; i++)
		free(fase[i]);
	free(fase);

	fileLevel.close();
}

void Fase::carregarFase(Jogador* player) {
	char valor[20];
	string pos;
	ifstream fileSave;
	fileSave.open(pathSave);

	if (!fileSave)
		return;

	int i = 0;
	int j;
	bool estado = false;
	ID id = vazio;
	Coord<float> posicao;
	fileSave >> valor[0];
	while (!fileSave.eof()) {
		fileSave >> valor[i];
		if (valor[i] == ':') {
			switch ((int)(valor[0]) - 48) {
			case((int)jogador):
				id = jogador;
				break;
			case((int)bombeta):
				id = bombeta;
				break;
			case((int)torreta):
				id = torreta;
				break;
			default:
				break;
			}
			if ((int)(valor[1] - 48))
				estado = true;
			else
				estado = false;
			i = -1;
		}
		else if (valor[i] == '-') {
			for (j = 0; j < i; j++)
				pos.push_back(valor[j]);
			posicao.x = stoi(pos);
			pos.clear();
			i = -1;
		}
		else if (valor[i] == '_') {
			for (j = 0; j < i; j++)
				pos.push_back(valor[j]);
			posicao.y = stoi(pos);

			Entidade* e = nullptr;
			if (id == jogador) {
				listaEntidadesMoveis->adicionarEntidade(player);
				player->setPosicao(posicao);
			}
			else if (id == bombeta)
				e = instanciaEntidade(posicao, bombeta);
			else if (id == torreta)
				e = instanciaEntidade(posicao, torreta);
			listaEntidadesMoveis->adicionarEntidade(e);
			if (id != jogador)
				e->setEstado(estado);
			pos.clear();
			i = -1;
		}
		i++;
	}

	fileSave.close();
}

bool Fase::chanceInimigo() {
	int r = rand() % 100;
	if (r > 50)
		return true;
	return false;
>>>>>>> Stashed changes
}