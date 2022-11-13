#include "Fases/Fase1.h"

Fase1::Fase1(){
	player = NULL;
	listaEntidades = new ListaEntidades();
}

void Fase1::Executar() {
	/*
	p1.Executar(Coord<float>(200, 450), Coord<float>(200, 50), sf::Color::White);
	p2.Executar(Coord<float>(350, 350), Coord<float>(100, 50), sf::Color::White);
	p3.Executar(Coord<float>(600, 300), Coord<float>(80, 50), sf::Color::White);
	p4.Executar(Coord<float>(0, 500), Coord<float>(850, 50), sf::Color::White);
	*/

	listaEntidades->adicionarEntidade(instanciaEntidade(Math::Coord<float>(50, 500), plataforma));
	//listaEntidades->(instaciaEntidade(Matematica::CoordenadaF(600.0f, -50.0f * i), 6));

}