#pragma once

#include <Ente.h>

namespace ElementosGraficos{
    class ElementoGrafico : public Ente {
    protected:
        sf::RectangleShape body;
    public:
        ElementoGrafico();

        virtual ~ElementoGrafico();

        void Executar();

        void imprimir();
    };
}