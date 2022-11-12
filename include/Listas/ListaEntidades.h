#pragma once
#include "Lista.h"
#include "Entidades/Entidade.h"

using namespace Entidades;

// Sem uso por enquanto.
namespace Listas {
	class ListaEntidades {
	public:
		Lista<Entidade> lista;

		ListaEntidades() {};
		~ListaEntidades() {};
	};
}
