#include "screen.h"
#include <iostream>
#include <string>
#include <windows.h>

void Screen::askNewGame()
{
    std::cout << "Хотите начать новую игру?\n('+' - да, '-' - нет)\nВведите ответ: ";
}

void Screen::askAnswer()
{
    std::cout << "Назовите букву: ";
}

void Screen::showWord(std::string word)
{
    std::cout << word << std::endl;
}

void Screen::showError()
{
    std::cout << "Некорректный ввод!" << std::endl;
}

void Screen::showCorrect()
{
    std::cout << "Откройте!" << std::endl << std::endl;
}

void Screen::showIncorrect()
{
    std::cout << "Нет такой буквы!" << std::endl << std::endl;
}

void Screen::showWin()
{
    std::cout << "Вы победили!" << std::endl;
}

void Screen::showStart()
{
    std::cout << "Игра началась!" << std::endl << std::endl;
}

void Screen::showEnd()
{
    std::cout << "Игра закончилась!" << std::endl << std::endl;
}

void Screen::showUsed()
{
    std::cout << "Такой ответ уже был!" << std::endl << std::endl;
}