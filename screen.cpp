#include "screen.h"
#include <iostream>
#include <string>
#include <windows.h>

void Screen::askNewGame()
{
    std::cout << "������ ������ ����� ����?\n('+' - ��, '-' - ���)\n������� �����: ";
}

void Screen::askAnswer()
{
    std::cout << "�������� �����: ";
}

void Screen::showWord(std::string word)
{
    std::cout << word << std::endl;
}

void Screen::showError()
{
    std::cout << "������������ ����!" << std::endl;
}

void Screen::showCorrect()
{
    std::cout << "��������!" << std::endl << std::endl;
}

void Screen::showIncorrect()
{
    std::cout << "��� ����� �����!" << std::endl << std::endl;
}

void Screen::showWin()
{
    std::cout << "�� ��������!" << std::endl;
}

void Screen::showStart()
{
    std::cout << "���� ��������!" << std::endl << std::endl;
}

void Screen::showEnd()
{
    std::cout << "���� �����������!" << std::endl << std::endl;
}

void Screen::showUsed()
{
    std::cout << "����� ����� ��� ���!" << std::endl << std::endl;
}