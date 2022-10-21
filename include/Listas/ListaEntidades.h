#pragma once
#include <list>
#include "Entidades/Entidade.h"

using namespace Entidades;

namespace Listas {
	class ListaEntidades {
	public:
		std::list<Entidade*> lista;

		ListaEntidades() {};
		~ListaEntidades() {};
	};
}
