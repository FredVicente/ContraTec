#pragma once

#include <iostream>
#include <map>

using namespace std;

namespace Entidades::Personagens{
    class Jogador;
}

class ControleJogador {
private:
    Entidades::Personagens::Jogador* pJogador;
    std::map<std::string, bool> keysPressed;
    std::string jump;
    std::string left;
    std::string right;
    std::string attack;
    std::string up;
    std::string down;

public:
    ControleJogador(Entidades::Personagens::Jogador* pJ = nullptr);

    ~ControleJogador();

    void notifyPressed(std::string tecla);

    void notifyReleased(std::string tecla);

    void setJogador(Entidades::Personagens::Jogador* p);

    void setTeclas(std::string jump, std::string up, std::string left, std::string down, std::string right, std::string attack);
};