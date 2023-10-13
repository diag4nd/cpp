#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>

bool isEmpty(std::array<std::array<char, 8>, 8>& board, int x, int y);

int findX(std::array<std::array<char, 8>, 8> &board, char name);

int findY(std::array<std::array<char, 8>, 8> &board, char name);

int getXPath(std::string direct);

int getYPath(std::string direct);

bool isPossible(std::array<std::array<char, 8>, 8>& board, char name, std::string direct);

void move(std::array<std::array<char, 8>, 8>& board, char name, std::string direct);

bool isCorrect(std::string line);

std::string getAnswer();

std::string getWhiteAnswer(std::array<std::array<char, 8>, 8>& board, char name);

bool isBKSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y);

bool isWKSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y);

bool isWRSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y);

int getRandPosition();

void showBoard(std::array<std::array<char, 8>, 8>& board);

void setDots(std::array<std::array<char, 8>, 8>& board);

void setBlackKing(std::array<std::array<char, 8>, 8>& board);

void setWhiteKing(std::array<std::array<char, 8>, 8>& board);

void setWhiteRook(std::array<std::array<char, 8>, 8>& board);


int main()
{
    std::srand(std::time(NULL));
    std::array<std::array<char, 8>, 8> board;

    // Будем считать, что:
    // Черный Король - это 'P'
    // Белый Король  - это 'K'
    // Белая Ладья   - это 'R'
    // Пустое поле   - это '.'
    setDots(board);
    setWhiteKing(board);
    setWhiteRook(board);
    setBlackKing(board);
    showBoard(board);

    std::string answer;
    while (true)
    {
        answer = getAnswer();
        move(board, 'P', answer);
        showBoard(board);
        
        int coin = rand()%2;
        char figure;
        if (coin == 0)
        {
          figure = 'K';
        }
        else
        {
          figure = 'R';
        }
        answer = getWhiteAnswer(board, figure);
        std::cout << "White turn: ";
        std::cout << figure << answer << std::endl;
        move(board, figure, answer);
        showBoard(board);
    }
    return 0;
}

bool isEmpty(std::array<std::array<char, 8>, 8>& board, int y, int x)
{
    if (board[y][x] == '.')
    {
        return true;
    }
    return false;
}

int findX(std::array<std::array<char, 8>, 8> &board, char name)
{
    int x = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == name)
            {
                x = j;
            }
        }
    }
    return x;
}

int findY(std::array<std::array<char, 8>, 8> &board, char name)
{
    int y = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == name)
            {
                //std::cout << 'y' << name << i << j << std::endl;
                y = i;
            }
        }
    }
    return y;
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

bool isPossible(std::array<std::array<char, 8>, 8>& board, char name, std::string direct)
{
    int x = getXPath(direct);
    int y = getYPath(direct);
    int x0 = findX(board, name);
    int y0 = findY(board, name);

    if ((x == x0) and (y == y0))
    {
        return false;
    }
    else if (name == 'P')
    {
        if ( (isWKSuitable(board, x, y)) and (isWRSuitable(board, x, y)) and (not isBKSuitable(board, x, y)) )
        {
            return true;
        }
        return false;
    }
    else if (name == 'K')
    {
        if ((isBKSuitable(board, x, y)) and (isWRSuitable(board, x, y)) and (not isWKSuitable(board, x, y)))
        {
            return true;
        }
        return false;
    }
    else
    {
        if ((isWKSuitable(board, x, y)) and (isBKSuitable(board, x, y)) and (not isWRSuitable(board, x, y)))
        {
            return true;
        }
        return false;
    }
}

void move(std::array<std::array<char, 8>, 8>& board, char name, std::string direct)
{
    int i, j, i0, j0;
    if (isPossible(board, name, direct))
    {
        j = getXPath(direct);
        i = getYPath(direct);
        j0 = findX(board, name);
        i0 = findY(board, name);
        board[i0][j0] = '.';
        board[i][j] = name;
    }
    else
    {
        std::cout << "Incorrect move" << std::endl;
        direct = getAnswer();
        move(board, name, direct);
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
               return true;
            }
        }
    }
    else
    {
        std::cout << "Incorrect answer" << std::endl;
        return false;
    }
}

std::string getAnswer()
{
    std::string ans;
    std::cout << "Black turn: ";
    std::getline(std::cin, ans);
    while (not isCorrect(ans))
    {
        return getAnswer();
    }
    return ans;
}

std::string getWhiteAnswer(std::array<std::array<char, 8>, 8>& board, char name)
{
  std::string ans = "00";
  int x = getRandPosition();
  int y = getRandPosition();
  char wx = 'a' + x;
  char wy = '1' + y;
  ans[0] = wx;
  ans[1] = wy;
  while (not isPossible(board, name, ans))
  {
    ans = getWhiteAnswer(board, name);
  }
  return ans;
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

bool isWRSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y)
{
    int WRx = findX(board, 'R');
    int WRy = findY(board, 'R');
    int flag;
    if ((x == WRx)  or (y == WRy))
    {
        if (x == WRx)
        {
            int imin{ 0 }, imax{ 0 };
            if (WRy < y)
            {
                imin = WRy;
                imax = y;
            }
            else
            {
                imin = y;
                imax = WRy;
            }
            flag = 0;
            for (int i = imin + 1; i < imax; i++)
            {
                if (not isEmpty(board, i, x))
                {
                    flag = 1;
                    break;
                }
            }
        }
        else if (y == WRy)
        {
            int jmin{ 0 }, jmax{ 0 };
            if (WRx < x)
            {
                jmin = WRx;
                jmax = x;
            }
            else
            {
                jmin = x;
                jmax = WRx;
            }
            flag = 0;
            for (int j = jmin + 1; j < jmax; j++)
            {
                if (not isEmpty(board, y, j))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
        {
            return true;
        }
        return false;
    }
    return true;
}

int getRandPosition()
{
    int randomVariable = std::rand() % 8;
    return randomVariable;
}

void showBoard(std::array<std::array<char, 8>, 8>& board)
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << 8 - i << "  ";
        for (int j = 0; j < 8; j++)
        {
            std::cout << board[i][j] << "   ";
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << "   ";
    for (int i = 0; i < 8; i++)
    {
        char temp = 'a' + i;
        std::cout << temp << "   ";
    }
    std::cout << std::endl << std::endl;
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

void setBlackKing(std::array<std::array<char, 8>, 8>& board)
{
    int x = getRandPosition();
    int y = getRandPosition();
    int whiteKingX = findX(board, 'K');
    int whiteKingY = findY(board, 'K');
    int whiteTowerX = findX(board, 'R');
    int whiteTowerY = findY(board, 'R');

    while ( (not isEmpty(board, x, y)) or (not isWKSuitable(board, x, y)) or (not isWRSuitable(board, x, y)) )
    {
        x = getRandPosition();
        y = getRandPosition();
    }
    int blackKingX = x;
    int blackKingY = y;
    board[blackKingY][blackKingX] = 'P';
}

void setWhiteKing(std::array<std::array<char, 8>, 8>& board)
{
    int x = getRandPosition();
    int y = getRandPosition();
    int whiteKingX = x;
    int whiteKingY = y;
    board[whiteKingY][whiteKingX] = 'K';
}

void setWhiteRook(std::array<std::array<char, 8>, 8>& board)
{
    int x = getRandPosition();
    int y = getRandPosition();
    int whiteKingX = findX(board, 'K');
    int whiteKingY = findY(board, 'K');

    while (not isEmpty(board, x, y))
    {
        x = getRandPosition();
        y = getRandPosition();
    }

    int whiteTowerX = x;
    int whiteTowerY = y;
    board[whiteTowerY][whiteTowerX] = 'R';
}
