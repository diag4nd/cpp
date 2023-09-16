#include <iostream>
#include <queue>                           // Подключение встроенной библиотеки для работы с очередями
#include <vector>                          // Подключение встроенной библиотеки для работы с векторами

#define SIZE 5

using namespace std;

int main()
{
    // Объявление статического массива
    int m[SIZE];

    // Объявление динамического массива
    int* mp = new int[SIZE];

    // Объявление очереди
    queue <int> q;

    // Объявление вектора
    vector <int> v = {0, 1, 2, 3, 4};

    for (int i = 0; i < SIZE; i++)
    {
        m [i] = i;
        mp[i] = i;
        q.push(i);
        cout << v.at(i) << "\t";
    }

    cout << endl << q.front();
    delete[] mp;
    return 0;
}
