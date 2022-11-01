#pragma once
#include "Entidade.h"

namespace Entidades {
<<<<<<< Updated upstream
	namespace Personagens{
		class Personagem : public Entidade{
		public:
			Coord<float> velocidade;
			Coord<float> aceleracao;
			int vidas = 3;
			bool pulo = false;
			bool andando = false;

			Personagem(ID id, Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f));
			~Personagem() {};
=======
	class Personagem : public Entidade {
	public:
		Coord<float> velocidade;
		Coord<float> aceleracao;
		int vidas = 3;
		bool pulo = false;
		bool andando = false;

		Personagem(ID id, Coord<float> posicao = Coord<float>(0.f, 0.f), Coord<float> tamanho = Coord<float>(0.f, 0.f));
		~Personagem() {};
>>>>>>> Stashed changes

			void Executar() {};

			void Mover();

<<<<<<< Updated upstream
			void Colisao(Entidade* e, int dir);
		};
	}
}
=======
		void Colisao(Entidade* e, int dir);
	};
}
>>>>>>> Stashed changes
