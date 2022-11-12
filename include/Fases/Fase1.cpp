#include "Fases/Fase1.h"

using namespace Fases;

Fase1::Fase1() {
	player = NULL;
	p1.Executar(Coord<float>(200, 450), Coord<float>(200, 50), sf::Color::White);
	p2.Executar(Coord<float>(350, 350), Coord<float>(100, 50), sf::Color::White);
	p3.Executar(Coord<float>(600, 300), Coord<float>(80, 50), sf::Color::White);
	p4.Executar(Coord<float>(0, 500), Coord<float>(850, 50), sf::Color::White);
	listaEntidades.lista.adicionar(&p1);
	listaEntidades.lista.adicionar(&p2);
	listaEntidades.lista.adicionar(&p3);
	listaEntidades.lista.adicionar(&p4);
}