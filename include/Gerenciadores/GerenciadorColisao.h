#pragma once
#include <Entidades/Personagem.h>
#include <Entidades/Plataforma.h>
#include <Listas/ListaEntidades.h>

using namespace Listas;

namespace Gerenciadores {
	class GerenciadorColisao
	{
	private:
		std::list<Entidade*>::iterator iterador1;
		std::list<Entidade*>::iterator iterador2;
	public:
		GerenciadorColisao() {};
		~GerenciadorColisao() {};

		void Colisao(ListaEntidades* lE);
	};
}

