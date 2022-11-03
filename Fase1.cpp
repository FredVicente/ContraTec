#include "Fases/Fase1.h"

using namespace Fases;

Fase1::Fase1() {
	player = NULL;
	p1.Inicializa(Coord<float>(200, 450), Coord<float>(200, 50), sf::Color::White);
	p2.Inicializa(Coord<float>(350, 350), Coord<float>(100, 50), sf::Color::White);
	p3.Inicializa(Coord<float>(600, 300), Coord<float>(80, 50), sf::Color::White);
	p4.Inicializa(Coord<float>(0, 500), Coord<float>(850, 50), sf::Color::White);
	lista.push_back(&p1);
	lista.push_back(&p2);
	lista.push_back(&p3);
	lista.push_back(&p4);
}