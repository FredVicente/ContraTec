#pragma once

#include <iostream>
#include <map>

namespace Entidades { class Jogador; };

class ControleJogador {
private:
    Entidades::Jogador* pJogador;
    std::map<std::string, bool> keysPressed;
    std::string jump;
    std::string left;
    std::string right;
    std::string attack;
    std::string up;
    std::string down;

public:
    ControleJogador(Entidades::Jogador* pJ = nullptr);

    ~ControleJogador() { pJogador = nullptr; };

    void notifyPressed(std::string tecla);

    void notifyReleased(std::string tecla);
};