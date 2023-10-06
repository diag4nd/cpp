#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <stdlib.h>
#include <string>

bool isPossible(char name, std::string direct)
{
	return true;
}

int getXPath(std::string direct)
{
	int x = direct[0] - 'a';
	return x;
}

int getYPath(std::string direct)
{
	int y = direct[1] - '1';
	return 7 - y;
}

void move(char name, std::string direct, std::array<std::array<char, 8>, 8>& board)
{
	int i, j, i0, j0;
	if (isPossible(name, direct))
	{
		i = getXPath(direct);
		j = getYPath(direct);
		i0 = findX(board, name);
		j0 = findY(board, name);
		board[i0][j0] = '.';
		board[i][j] = name;
	}
}

bool isCorrect(std::string line)
{
	if (line.length() == 2)
	{
		if ((line[0] >= 'a') and ((line[0] <= 'h')))
		{
			if ((line[1] >= '1') and ((line[1] <= '8')))
			{
				std::cout << "Correct answer" << std::endl;
				return true;
			}
		}
	}
	std::cout << "Incorrect answer" << std::endl;
	return false;
}

std::string getAnswer()
{
	std::string ans;
	std::cout << "Your turn: ";
	std::getline(std::cin, ans);
	while (not isCorrect(ans))
	{
		std::cout << "Your turn: ";
		std::getline(std::cin, ans);
	}
	return ans;
}

int findX(std::array<std::array<char, 8>, 8>& board, char name)
{
	int x;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == name)
			{
				x = i;
			}
		}
	}
	return x;
}

int findY(std::array<std::array<char, 8>, 8>& board, char name)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == name)
			{
				return j;
			}
		}
	}
}

bool isBKSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y)
{
	int BKx = findX(board, 'P');
	int BKy = findY(board, 'P');
	if ((abs(BKx - x) <= 1) and (abs(BKy - y) <= 1))
	{
		return false;
	}
	return true;
}

bool isWKSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y)
{
	int WKx = findX(board, 'K');
	int WKy = findY(board, 'K');
	if ((abs(WKx - x) <= 1) and (abs(WKy - y) <= 1))
	{
		return false;
	}
	return true;
}

int getRandPosition()
{
	int randomVariable = std::rand()%8;
	return randomVariable;
}

void showBoard(std::array<std::array<char, 8>, 8> &board)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << 8-i << '|' << '\t';
		for (int j = 0; j < 8; j++)
		{
			std::cout << board[i][j] << '\t';
		}
		std::cout << '|' << std::endl << " | " << std::endl;
	}
	
}

void setDots(std::array<std::array<char, 8>, 8>& board)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = '.';
		}
	}
}

void setBlackKing(std::array<std::array<char, 8>, 8> &board)
{
	int blackKingX = getRandPosition();
	int blackKingY = getRandPosition();
	board[blackKingX][blackKingY] = 'P';
}

void setWhiteKing(std::array<std::array<char, 8>, 8> &board)
{
	int x = getRandPosition();
	int y = getRandPosition();
	while (not isBKSuitable(board, x, y))
	{
		x = getRandPosition();
		y = getRandPosition();
	}
	int whiteKingX = x;
	int whiteKingY = y;
	board[whiteKingX][whiteKingY] = 'K';
}

void setWhiteTower(std::array<std::array<char, 8>, 8>& board)
{
	int x = getRandPosition();
	int y = getRandPosition();
	while ( not (isBKSuitable(board, x, y) and (isWKSuitable(board, x, y))) )
	{
		x = getRandPosition();
		y = getRandPosition();
	}
	int whiteKingX = x;
	int whiteKingY = x;
	board[whiteKingX][whiteKingY] = 'T';
}

int main()
{
	std::srand(std::time(NULL));
	std::array<std::array<char, 8>, 8> board;
	// Будем считать, что
	// Черный Король - это 'P'
	// Белый Король  - это 'K'
	// Белая Ладья   - это 'T'
	// Пустое поле   - это '*'

	setDots(board);
	setBlackKing(board);
	setWhiteKing(board);
	setWhiteTower(board);
	showBoard(board);

	std::string answer;
	answer = getAnswer();
	return 0;
}
