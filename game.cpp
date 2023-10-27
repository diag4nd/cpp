#include "game.h"
#include <iostream>
#include <string>
#include <windows.h>

void Game::setPower()
{
    std::string ans;
    std::getline(std::cin, ans);
    power = ans;
}

bool Game::isCorrectPower()
{
    if (power.length() != 1)
    {
        return false;
    }
    else if (not ((power[0] == '+') or (power[0] == '-')))
    {
        return false;
    }
    return true;
}