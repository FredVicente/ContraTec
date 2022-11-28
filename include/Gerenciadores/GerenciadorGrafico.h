#pragma once
#include <Math/Coord.h>
#include <SFML/Graphics.hpp>
#include <map>
/*
* Baseado no codigo do atual monitor de
* engenharia da computação, Giovane Limas Salvi.
*/

using namespace Math;

namespace Gerenciadores {

    class GerenciadorGrafico {
    private:
        sf::RenderWindow* window;
        sf::View view;

        /* Padrao de projeto Singleton */
        static GerenciadorGrafico* instancia;
        GerenciadorGrafico();

    public:
        ~GerenciadorGrafico();

        static GerenciadorGrafico* getInstancia();

        sf::View* getView() { return &view; };

        void renderizar(sf::RectangleShape* body);

        void renderizar(sf::Text* text);

        void display();

        void clear();

        bool janelaAberta() const;

        void fecharJanela();

        void setTamanhoJanela(Coord<int> size);

        Coord<int> getTamanhoJanela() const;

        //Coord<float> getTopLeftPosition() const;

        void centralizarView(float posX);
        void centralizarView();

        //sf::Texture* loadTexture(const char* path);

        //sf::Font* loadFont(const char* path);

        //float updateDeltaTime();

        sf::RenderWindow* getJanela() const;

        sf::Texture carregarTextura(const char* caminhoTextura);
    };

}