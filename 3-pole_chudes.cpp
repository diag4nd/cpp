#include <iostream>
#include <string>
#include <windows.h>

std::string getWord      ()
{
	std::string word;

	std::cout << "Введите слово: ";
	std::cin  >> word;
	return word;
}

void        putWord      (std::string word)
{
	std::cout << word << std::endl;
}

char        getLetter    ()
{
	char letter;
	std::cout << "Введите букву: ";
	std::cin >> letter;
	return letter;
}

bool        isClosed     (char letter)
{
	if (letter == '-')
	{
		return true;
	}
	return false;
}

void        changeLetter (std::string &displayWord, char letter, int index)
{
	displayWord[index] = letter;
}

void        openLetter   (std::string winWord, std::string &displayWord, char letter)
{
	for (int i = 0; i < winWord.length(); i++)
	{
		if ((winWord[i] == letter) and (isClosed(displayWord[i])))
		{
				changeLetter(displayWord, letter, i);
		}
	}
	std::cout << "Угадали!" << std::endl << std::endl << std::endl;
	putWord(displayWord);
}

void        tryAgain     ()
{
	std::cout << "Нет такой буквы!" << std::endl << std::endl << std::endl;
}

bool        isFinished   (std::string displayWord)
{
	for (int i = 0; i < displayWord.length(); i++)
	{
		if (isClosed(displayWord[i]))
		{
			return false;
		}
	}
	return true;
}

bool        isRight      (std::string word, char answer)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == answer)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	// Следующие команды из файла <windows.h> нужны для корректного использования кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string winWord;

	winWord = getWord();

	std::string displayWord (winWord.length(), '-');

	putWord(displayWord);

	char answer;
	while (not isFinished(displayWord))
	{
		answer = getLetter();
		if (isRight(winWord, answer))
		{
			openLetter(winWord, displayWord, answer);
		}
		else
		{
			tryAgain();
			putWord(displayWord);
		}
	}
	std::cout << "Вы угадали слово - " << winWord << "! Поздравляю!" << std::endl;
}
