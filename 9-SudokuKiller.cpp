#include <iostream>
#include <vector>
#include <array>

int main()
{
    std::array<int, 9> numbers{ 1, 2, 3, 4, 5, 6, 8, 9 };
    std::array<int, 9> flags{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    std::array<int, 9> exception{ 2, 4, 6 };
    for (int i = 0; i < 9; i++)
    {
        if (exception[i] != 0)
        {
            flags[exception[i]-1] = 1;
        }
    }

    int j = 0;
    for (int i = 0; i < 9; i++)
    {
        if (flags[i] == 0)
        {
            j++;
        }
    }
    const int len = j;

    std::array<int, 9> goodNumbers;
    j = 0;
    for (int i = 0; i < 9; i++)
    {
        if (flags[i] == 0)
        {
            goodNumbers[j] = i+1;
            j++;
        }
    }
    /*
    for (int i = 0; i < len; i++)
    {
        std::cout << goodNumbers[i] << std::endl;
    }
    */
    int s = 5;
    /*
    std::cout << "Input summ:";
    std::cin >> s;
    while (!((s >= 0) and (s <= 45)))
    {
        std::cout << "Incorrect input!" << std::endl;
        std::cout << "Input summ:";
        std::cin >> s;
    }
    */
    int n = 9;
    /*
    std::cout << "Input number:";
    std::cin >> n;
    while (!((n >= 1) and (s <= 9)))
    {
        std::cout << "Incorrect input!" << std::endl;
        std::cout << "Input summ:";
        std::cin >> s;
    }
    */
    if (len < n)
    {
        std::cout << "No!";
        return 1;
    }


    return 0;
}
