#include<iostream>
#include <string>
#include <windows.h>

unsigned long long fibonacci(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    return ( fibonacci(x - 1) + fibonacci(x - 2) );
}

std::string getAnswer()
{
    std::cout << "Введите натуральное число от 1 до 100: ";
    std::string word;
    std::getline(std::cin, word);
    return word;
}

bool isString(std::string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (not isdigit(word[i]))
        {
            return true;
        }
    }
    return false;
}

bool isFloat(std::string word)
{
    int dotNum = 0;
    if (isdigit(word[0]))
    {
        for (int i = 1; i < word.length(); i++)
        {
            if (not isdigit(word[i]))
            {
                if ((word[i] == '.') and (dotNum == 0))
                {
                    dotNum++;
                }
                else
                {
                    return false;
                }
            }
        }
        if (dotNum == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool isBig(int num)
{
    if (num > 100)
    {
        return true;
    }
    return false;
}

bool isSmall(int num)
{
    if (num < 1)
    {
        return true;
    }
    return false;
}

bool isAcceptable(std::string ans)
{
    if (isFloat(ans))
    {
        std::cout << "Нецелое число" << std::endl;
        return false;
    }
    else if (not isString(ans))
    {
        int ansInt;
        unsigned long long fib;
        ansInt = std::stoi(ans);

        if (isBig(ansInt))
        {
            std::cout << "Слишком большое" << std::endl;
            return false;
        }
        else if (isSmall(ansInt))
        {
            std::cout << "Слишком маленькое" << std::endl;
            return false;
        }
        for (int i = 0; i <= ansInt; i++)
        {
            std::cout << fibonacci(i) << ' ';
        }
        return true;
    }
    else
    {
        std::cout << "Недопустимый формат" << std::endl;
        return false;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string ans;
    ans = getAnswer();

    while (not isAcceptable(ans))
    {
        ans = getAnswer();
    }
    return 0;
}
