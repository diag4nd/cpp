#ifndef GAME_H
#define GAME_H

class Game
{
private:
    int status;
    std::string power;

public:
    Game() : status{ 0 }, power{ '+' }
    {}
    void startGame() { status = 1; };
    void checkGame() { status = 2; };
    void endGame() { status = 3; };
    int getStatus() const { return status; };
    void setPower();
    bool isCorrectPower();
    char getPower() const { return power[0]; };
};

#endif