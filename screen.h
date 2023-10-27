#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
public:
    void askNewGame();
    void askAnswer();
    void showWord(std::string word);
    void showError();
    void showCorrect();
    void showIncorrect();
    void showWin();
    void showStart();
    void showEnd();
    void showUsed();
};

#endif