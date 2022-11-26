#pragma once

#include <Ente.h>

namespace ElementosGraficos{
    class ElementoGrafico : public Ente {
    protected:
        sf::RectangleShape body;
    public:
        ElementoGrafico() {};

        ~ElementoGrafico(){};

        void Executar(){};

        virtual void imprimir(){
            gGrafico->renderizar(&body);
        };
    };
}