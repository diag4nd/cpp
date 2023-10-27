#include <iostream>
#include <string>
#include <windows.h>
#include "game.cpp"
#include "provider.cpp"
#include "screen.cpp"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Game poleChudes;
    Provider jacub;
    Screen screen;

    screen.askNewGame();
    poleChudes.setPower();
    while (not poleChudes.isCorrectPower())
    {
        screen.showError();
        screen.askNewGame();
        poleChudes.setPower();
    }
    while (poleChudes.getPower() != '-')
    {
        poleChudes.startGame();
        screen.showStart();

        jacub.setWinWord("Doorbell");
        jacub.setScreenWord();

        screen.showWord(jacub.getScreenWord());
        while (poleChudes.getStatus() != 2)
        {
            screen.askAnswer();
            jacub.setAnswer();
            while (not (jacub.isCorrectAnswer()))
            {
                screen.showError();
                screen.askAnswer();
                jacub.setAnswer();
            }
            if (not jacub.isUsedAnswer())
            {
                jacub.rememberAnswer();
                if (jacub.isRightAnswer())
                {
                    screen.showCorrect();
                    jacub.openLetter();
                }
                else
                {
                    screen.showIncorrect();
                }

                screen.showWord(jacub.getScreenWord());
                if (jacub.isFinished())
                {
                    poleChudes.checkGame();
                }
            }
            else
            {
                screen.showUsed();
            }
        }
        screen.showWin();
        poleChudes.endGame();
        screen.showEnd();

        screen.askNewGame();
        poleChudes.setPower();
    }
    return 0;
}
