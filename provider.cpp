#include "provider.h"
#include <iostream>
#include <string>
#include <windows.h>

void Provider::setWinWord(std::string word)
{
    winWord = word;
}

void Provider::setScreenWord()
{
    std::string line(winWord.length(), '_');
    screenWord = line;
}

void Provider::setAnswer()
{
    std::string ans;
    std::getline(std::cin, ans);
    answer = ans;
}

bool Provider::isCorrectAnswer()
{
    if (answer.length() != 1)
    {
        return false;
    }
    else if (not (((answer[0] >= 'a') and (answer[0] <= 'z')) or ((answer[0] >= 'A') and (answer[0] <= 'Z')) or ((answer[0] >= 'à') and (answer[0] <= 'ÿ')) or ((answer[0] >= 'À') and (answer[0] <= 'ß'))))
    {
        return false;
    }
    return true;
}

bool Provider::isRightAnswer()
{
    for (int i = 0; i < winWord.length(); i++)
    {
        if ((answer[0] == winWord[i]) and (screenWord[i] == '_'))
        {
            return true;
        }
    }
    return false;
}

bool Provider::isUsedAnswer()
{
    for (int i = 0; i < answerLog.length(); i++)
    {
        if (answerLog[i] == answer[0])
        {
            return true;
        }
    }
    return false;
}

void Provider::rememberAnswer()
{
    answerLog += answer[0];
}

bool Provider::isFinished()
{
    for (int i = 0; i < winWord.length(); i++)
    {
        if (screenWord[i] == '_')
        {
            return false;
        }
    }
    return true;
}

void Provider::openLetter()
{
    for (int i = 0; i < winWord.length(); i++)
    {
        if (winWord[i] == answer[0])
        {
            screenWord[i] = answer[0];
        }
    }
}