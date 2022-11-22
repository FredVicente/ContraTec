#include "Fase.h"

using namespace Fases;

Fase::Fase() {
	listaEntidadesMoveis = nullptr;
	listaEntidadesEstaticas = nullptr;
	player = nullptr;
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

void Fase::criarFase(const char* path) {
	ifstream file;
	const int y = 13, x = 30;
	char fase[y][x];

	file.open(path);

	if (!file) {
		cout << "ERROR: caminho invalido para fase!" << endl;
		exit(54);
	}

	listaEntidadesMoveis->adicionarEntidade(player);
	
	int i, j;
	while (!file.eof()) {
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				file >> fase[i][j];

				if (fase[i][j] == 'J')
					player->setPosicao(Coord<float>(j * 50, i * 50));
				else if (fase[i][j] == 'P')
					listaEntidadesEstaticas->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), plataforma));
				else if(fase[i][j] == 'B')
					listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), bombeta));
				else if(fase[i][j] == 'T')
					listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), torreta));
			}
		}
	}

	file.close();
}