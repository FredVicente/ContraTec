#include "Fase.h"

using namespace Fases;

int Fase::faseAtual = 1;

Fase::Fase(Jogador* p, const char* backgroundPath, string path) :
	backgroundShape(sf::Vector2f(1300,700)),
	backgroundTexture(gGrafico->carregarTextura(backgroundPath)){
	listaEntidadesEstaticas = new ListaEntidades;
	listaEntidadesMoveis = new ListaEntidades;
	listaPlataformas = new ListaEntidades;
	player = p;
	player->setFase(this);
	pathSave = path;

	fonte.loadFromFile("Fonts/AstroSpace.ttf");
	vidas.setFont(fonte);
	vidas.setCharacterSize(30);
	pontos.setFont(fonte);
	pontos.setCharacterSize(30);
	backgroundShape.setTexture(&backgroundTexture);
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
	sf::RenderWindow* window = gGrafico->getJanela();
	sf::View* view = gGrafico->getView();

	backgroundShape.setPosition(view->getCenter() - sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
	window->draw(backgroundShape);

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
	case(elevador):{
		Elevador* e = new Elevador(pos, 100, 30, 60);
		return e;
	}
	case(torreEletrica):{
		TorreEletrica* t = new TorreEletrica(pos);
		return t;
	}
	case(reiRobo):{
		ReiRobo* r = new ReiRobo(pos, player, 1);
		r->setFase(this);
		return r;
	}
	default:
		break;
	}
	return nullptr;
}

void Fase::criarFase(const char* path, Jogador* player, Coord<int> tamanho) {
	ifstream fileLevel;
	char** fase = (char**) malloc(tamanho.y * sizeof(char*));

	int i, j;
	for (i = 0; i < tamanho.y; i++) {
		fase[i] = (char*)malloc(tamanho.x * sizeof(char));
	}

	fileLevel.open(path);

	if (!fileLevel) {
		cout << "ERROR: caminho invalido para fase!" << endl;
		exit(54);
	}

	while (!fileLevel.eof()) {
		for (i = 0; i < tamanho.y; i++) {
			for (j = 0; j < tamanho.x; j++) {
				fileLevel >> fase[i][j];

				if (fase[i][j] == 'p')
					listaEntidadesEstaticas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), plataforma));
				if (pathSave == "") {
					if (fase[i][j] == 'P')
						listaPlataformas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), plataforma));
					else if (fase[i][j] == 'J') {
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
					else if(fase[i][j] == 'E')
						listaPlataformas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), elevador));
					else if(fase[i][j] == 'e' && chanceInimigo())
						listaPlataformas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), elevador));
					else if(fase[i][j] == 'V')
						listaPlataformas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), torreEletrica));
					else if(fase[i][j] == 'v' && chanceInimigo())
						listaPlataformas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), torreEletrica));
					else if(fase[i][j] == 'R')
						listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), reiRobo));				
				}
			}
		}
	}

	if (pathSave != "")
		carregarFase();

	for (i = 0; i < tamanho.y; i++)
		free(fase[i]);
	free(fase);

	fileLevel.close();

	listaEntidadesEstaticas->executarTodos();
	listaEntidadesMoveis->executarTodos();
	listaPlataformas->executarTodos();
}

void Fase::carregarFase() {
	string valor;
	ifstream fileSave;
	fileSave.open(pathSave);

	fileSave >> valor;
	fileSave >> valor;
	fileSave >> valor;

	bool estado = false;
	ID id = vazio;
	Coord<float> posicao;

	while (!fileSave.eof()) {
		fileSave >> valor;
		if (stoi(valor))
			estado = true;
		else
			estado = false;
		
		fileSave >> valor;
		posicao.x = stoi(valor);

		fileSave >> valor;
		posicao.y = stoi(valor);

		fileSave >> valor;
		Entidade* e = nullptr;
		bool plat = false;

		switch (stoi(valor)) {
		case((int)jogador):
			e = player;
			player->setPosicao(posicao);
			break;
		case((int)bombeta):
			e = instanciaEntidade(posicao, bombeta);
			break;
		case((int)torreta):
			e = instanciaEntidade(posicao, torreta);
			break;
		case((int)reiRobo):
			e = instanciaEntidade(posicao, reiRobo);
			break;
		case((int)plataforma):
			e = instanciaEntidade(posicao, plataforma);
			plat = true;
			break;
		case((int)elevador):
			e = instanciaEntidade(posicao, elevador);
			plat = true;
			break;
		case((int)torreEletrica):
			e = instanciaEntidade(posicao, torreEletrica);
			plat = true;
			break;
		default:
			break;
		}
		if (!e) {
			cout << "ERROR: entidade salva nulo!";
			exit(1);
		}
		if (!plat)
			listaEntidadesMoveis->adicionarEntidade(e);
		else
			listaPlataformas->adicionarEntidade(e);
		e->setEstado(estado);
	}

	fileSave.close();
}

bool Fase::chanceInimigo() {
	int r = rand() % 100;
	if (r > 50)
		return true;
	return false;
}