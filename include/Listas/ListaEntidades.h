#pragma once
#include <list>
#include "Entidades/Entidade.h"

using namespace Entidades;

// Sem uso por enquanto.
namespace Listas {
	class ListaEntidades {
	public:
		std::list<Entidade*> lista;

		ListaEntidades() {};
		~ListaEntidades() {};
	};
}
