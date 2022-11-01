#pragma once

#include <iostream>
#include <map>

<<<<<<< Updated upstream
using namespace std;

namespace Entidades::Personagens{
    class Jogador;
}

class ControleJogador {
private:
    Entidades::Personagens::Jogador* pJogador;
=======
namespace Entidades { class Jogador; };

class ControleJogador {
private:
    Entidades::Jogador* pJogador;
>>>>>>> Stashed changes
    std::map<std::string, bool> keysPressed;
    std::string jump;
    std::string left;
    std::string right;
    std::string attack;
    std::string up;
    std::string down;

public:
<<<<<<< Updated upstream
    ControleJogador(Entidades::Personagens::Jogador* pJ = nullptr);

    ~ControleJogador();
=======
    ControleJogador(Entidades::Jogador* pJ = nullptr);

    ~ControleJogador() { pJogador = nullptr; };
>>>>>>> Stashed changes

    void notifyPressed(std::string tecla);

    void notifyReleased(std::string tecla);
<<<<<<< Updated upstream

    void setJogador(Entidades::Personagens::Jogador* p);

    void setTeclas(std::string jump, std::string up, std::string left, std::string down, std::string right, std::string attack);
=======
>>>>>>> Stashed changes
};