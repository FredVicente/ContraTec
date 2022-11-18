#include "Fase.h"

using namespace Fases;

Fase::Fase() {
	listaEntidadesMoveis = nullptr;
	listaEntidadesEstaticas = nullptr;
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

void Fase::criarFase(const char* path, Jogador* player) {
	ifstream file;
	const int y = 12, x = 176;
	char fase[y][x];

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
				else if (fase[i][j] == 'J')
					player->setPosicao(Coord<float>(j * 50, i * 50));
			}
		}
	}

	file.close();
}