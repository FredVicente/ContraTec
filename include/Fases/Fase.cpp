#include "Fase.h"

using namespace Fases;

int Fase::faseAtual = 0;

Fase::Fase() {
	player = nullptr;
	listaEntidadesMoveis = nullptr;
	listaEntidadesEstaticas = nullptr;
}

void Fase::clear() {
	if (listaEntidadesEstaticas) {
		listaEntidadesEstaticas->lista.clear();
		listaEntidadesMoveis->lista.clear();
	}
}

Entidade* Fase::instanciaEntidade(Coord<float> pos, ID id) {
	switch (id) {
	case (plataforma): {
		Plataforma* p = new Plataforma(pos);
		return p;
	}
	case(jogador):	{
		Jogador* j = new Jogador(pos, Coord<float>(50,80));
		player = j;
		return j;
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
				else if (fase[i][j] == 'J')
					listaEntidadesMoveis->adicionarEntidade(instanciaEntidade(Coord<float>(j * 50, i * 50), jogador));
			}
		}
	}

	for (i = 0; i < tamanho.y; i++) {
		free(fase[i]);
	}
	free(fase);

	file.close();
}