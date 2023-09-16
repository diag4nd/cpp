#include <iostream>
using namespace std;

int main()
{
                                                    // Задание с указателями
    double** pointer;
    double** p;
    double   number = 2.0;

    pointer  = (double**) malloc(sizeof *pointer);  // Выделение памяти под двойной указатель
    *pointer = (double*)  malloc(sizeof number);

    *pointer = &number;
    pointer  = &(*pointer);

    cout << **pointer << endl;
    free(*pointer);        
                                                    // Освобождение памяти. Конец задания

    return 0;
}

