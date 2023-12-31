#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#define N 14

int main()
{
    std::string music  [N]{ "Master of puppets Metallica", "Брошу Pyrokinesis", "Homebody PH1", "Червяк Даргомыжский", "Russian Ebunny", "Enemy Imagine dragons", " Зизазай Огги и тараканы", "Valentine Justice", "Swimming pools Kendrick Lamar", "Night Call Kovinsky", "Yesterday The Beatles", "Так закалялась сталь Гражданская оборона", "За деньги да Инстасамка", "Bad habits Ed sheeran" };
    std::string movies [N]{ "Короткое замыкание", "Трансформеры", "Полночь", "По соображениям совести", "Джентльмены", "Ван Хельсинк", "Операция Ы", "Драйв", "Большая игра", "Игра в имитацию", "Всё везде и сразу", "Форрест Гамп", "Терминал", "Не смотрите наверх" };
    std::string actors [N]{ "Райан Гослинг", "Кристиан Бейл", "Джеки Чан", "Эндрю Гарфилд", "Леонардо ДиКаприо", "Бенедикт Кембербетч", "Мэтью Макконахи", "Дэвид Линч", "Дэниэлл Рэдклифф", "Джейк Джиллехолл", "Александр Петров", "Рональд Рейган", "Том Круз", "Брэд Питт" };
    std::string actriss[N]{ "Наталия Крачковская", "Меган Фокс", "Джениффер Лопез", "Эмма Стоун", "Эмма Уотсон", "Кира Найтли", "Милла Йовович", "Марго Робби", "Мерил Стрип", "Скарлет Йоханссон", "Александра Бортич", "Анджелина Джоли", "Шарлиз Терон", "Ингеборга Дапкунайте" };
    std::string celeb  [N]{ "Дейв Майнстейн", "Иван Зола", "Сергей Мавроди", "Екатерина Гордеева", "Роберт Опенгеймер", "Лионель Месси", "Папич", "Хидэо Кодзима", "Ляйсан Утяшева", "Павел Воля", "Криштиану Роналду", "Борис Бурда", "Ким Кардашьян", "Клава Кока" };
    
    std::string date{ "15.12.2003" };

    int summ = 0;
    int j                   = 0;
    int month               = 0;
    for (int i = 0; i < date.length(); i++)
    {
        if (isdigit(date[i]))
        {
            summ += int(date[i]) - int('0');
            if (i == 3)
            {
                month += int(date[i] - int('0'));
                month += int(date[i+1] - int('0'));
            }
        }
    }

    int randArray[3]{ 0, 11111111, 22222222 };
    srand(time(NULL));
    int i = rand() % 3;
    summ  = pow(summ, month);
    summ += randArray[i];


    std::cout << summ;
    return 0;
}
