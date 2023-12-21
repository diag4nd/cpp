#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::pair<char, int> pair;

std::vector<pair> top10(std::map<char, long long unsigned int> part);
std::vector<pair> sort(std::vector<pair>);

int main()
{
    setlocale(LC_ALL, "Russian");

    std::map<char, long long unsigned int> part1;
    std::map<char, long long unsigned int> part2;
    std::map<char, long long unsigned int> part3;
    std::map<char, long long unsigned int> part4;

    std::string text{};
    std::ifstream MyReadFile1("voyna-i-mir-tom-1.txt");
    int i(0);
    while (std::getline(MyReadFile1, text))
    {
        for (int k(0); k < text.size(); k++)
        {

            text[k] = toupper(text[k]);
            if ((text[k] >= 'А') and (text[k] <= 'Я'))
            {
                if (part1.count(text[k]))
                {
                    part1[text[k]] += 1;
                }
                else
                {
                    part1[text[k]] = 1;
                }
            }
        }
    }
    MyReadFile1.close();
    std::ifstream MyReadFile2("voyna-i-mir-tom-2.txt");
    i = 0;
    while (std::getline(MyReadFile2, text))
    {
        for (int k(0); k < text.size(); k++)
        {

            text[k] = toupper(text[k]);
            if ((text[k] >= 'А') and (text[k] <= 'Я'))
            {
                if (part2.count(text[k]))
                {
                    part2[text[k]] += 1;
                }
                else
                {
                    part2[text[k]] = 1;
                }
            }
        }
    }
    MyReadFile2.close();
    std::ifstream MyReadFile3("voyna-i-mir-tom-3.txt");
    i = 0;
    while (std::getline(MyReadFile3, text))
    {
        for (int k(0); k < text.size(); k++)
        {

            text[k] = toupper(text[k]);
            if ((text[k] >= 'А') and (text[k] <= 'Я'))
            {
                if (part3.count(text[k]))
                {
                    part3[text[k]] += 1;
                }
                else
                {
                    part3[text[k]] = 1;
                }
            }
        }
    }
    MyReadFile3.close();
    std::ifstream MyReadFile4("voyna-i-mir-tom-4.txt");
    i = 0;
    while (std::getline(MyReadFile4, text))
    {
        for (int k(0); k < text.size(); k++)
        {

            text[k] = toupper(text[k]);
            if ((text[k] >= 'А') and (text[k] <= 'Я'))
            {
                if (part4.count(text[k]))
                {
                    part4[text[k]] += 1;
                }
                else
                {
                    part4[text[k]] = 1;
                }
            }
        }
    }
    MyReadFile4.close();


    std::vector<pair> top101{};
    std::vector<pair> top102{};
    std::vector<pair> top103{};
    std::vector<pair> top104{};
    top101 = top10(part1);
    top102 = top10(part2);
    top103 = top10(part3);
    top104 = top10(part4);

    std::cout << "Part 1" << std::endl;
    for (const auto& element : top101)
    {
        std::cout << element.first << "\t" << element.second << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Part 2" << std::endl;
    for (const auto& element : top102)
    {
        std::cout << element.first << "\t" << element.second << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Part 3" << std::endl;
    for (const auto& element : top103)
    {
        std::cout << element.first << "\t" << element.second << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Part 4" << std::endl;
    for (const auto& element : top104)
    {
        std::cout << element.first << "\t" << element.second << std::endl;
    }
    std::cout << std::endl;
}

std::vector<pair> top10(std::map<char, long long unsigned int> part)
{
    std::vector<pair> vec{};
    std::copy(part.begin(), part.end(), std::back_inserter<std::vector<pair>>(vec));
    std::sort(vec.begin(), vec.end(),
    [](const pair& l, const pair& r)
        {
            if (l.second != r.second) {
                return l.second < r.second;
            }

            return l.first < r.first;
        });
    vec.erase(vec.begin(), vec.end() - 10);
    std::reverse(vec.begin(), vec.end());
    return vec;
}
