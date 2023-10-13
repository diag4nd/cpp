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

bool isBKSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y);

bool isWKSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y);

bool isWTSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y);

int getRandPosition();

void showBoard(std::array<std::array<char, 8>, 8>& board);

void setDots(std::array<std::array<char, 8>, 8>& board);

void setBlackKing(std::array<std::array<char, 8>, 8>& board);

void setWhiteKing(std::array<std::array<char, 8>, 8>& board);

void setWhiteTower(std::array<std::array<char, 8>, 8>& board);

int main()
{
    std::srand(std::time(NULL));
    std::array<std::array<char, 8>, 8> board;

    // Будем считать, что
    // Черный Король - это 'P'
    // Белый Король  - это 'K'
    // Белая Ладья   - это 'T'
    // Пустое поле   - это '.'
    setDots(board);
    setWhiteKing(board);
    setWhiteTower(board);
    setBlackKing(board);
    showBoard(board);

    std::string answer;
    while (true)
    {
        answer = getAnswer();
        move(board, 'P', answer);
        showBoard(board);
    }
    return 0;
}

bool isEmpty(std::array<std::array<char, 8>, 8>& board, int x, int y)
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
                //std::cout << 'x' << name << i << j << std::endl;
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
        if ((isWKSuitable(board, x, y)) and (isWTSuitable(board, x, y)) and (not isBKSuitable(board, x, y)) )
        {
            return true;
        }
        return false;
    }
    else if (name == 'K')
    {
        if ((isBKSuitable(board, x, y)) and (isWTSuitable(board, x, y)))
        {
            if (not isWKSuitable(board, x, y))
            {
                return true;
            }
            return false;
        }
        return false;
    }
    else if (name == 'T')
    {
        if ((isWKSuitable(board, x, y)) and (isBKSuitable(board, x, y)))
        {
            if (not isWTSuitable(board, x, y))
            {
                return true;
            }
            return false;
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
                std::cout << "Correct answer" << std::endl << std::endl;
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
    std::cout << "Black turn: ";
    std::getline(std::cin, ans);
    while (not isCorrect(ans))
    {
        std::cout << "Black turn: ";
        std::getline(std::cin, ans);
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

bool isWTSuitable(std::array<std::array<char, 8>, 8>& board, int x, int y)
{
    int WTx = findX(board, 'T');
    int WTy = findY(board, 'T');
    int flag;
    if ((x == WTx) or (y == WTy))
    {
        if (x == WTx)
        {
            int imin{ 0 }, imax{ 0 };
            if (WTy < y)
            {
                imin = WTy;
                imax = y;
            }
            else
            {
                imin = y;
                imax = WTy;
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
        else if (y == WTy)
        {
            int jmin{ 0 }, jmax{ 0 };
            if (WTx < x)
            {
                jmin = WTx;
                jmax = x;
            }
            else
            {
                jmin = x;
                jmax = WTx;
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
    //std::cout << "P-y:" << y << " x:" << x << std::endl;
    //std::cout << "START" << std::endl;
    int whiteKingX = findX(board, 'K');
    int whiteKingY = findY(board, 'K');
    int whiteTowerX = findX(board, 'T');
    int whiteTowerY = findY(board, 'T');

    while ( (not isEmpty(board, x, y)) or (not isWKSuitable(board, x, y)) or (not isWTSuitable(board, x, y)) )
    {
        x = getRandPosition();
        y = getRandPosition();
        //std::cout << "P-y:" << y << " x:" << x << std::endl;
    }
    int blackKingX = x;
    int blackKingY = y;
    //std::cout << 'P' << blackKingY << blackKingX << std::endl;
    //std::cout << "END" << std::endl;
    board[blackKingY][blackKingX] = 'P';
}

void setWhiteKing(std::array<std::array<char, 8>, 8>& board)
{
    int x = getRandPosition();
    int y = getRandPosition();
    int whiteKingX = x;
    int whiteKingY = y;
    //std::cout << 'K' << whiteKingY << whiteKingX << std::endl;
    board[whiteKingY][whiteKingX] = 'K';
}

void setWhiteTower(std::array<std::array<char, 8>, 8>& board)
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
    //std::cout << 'T' << whiteTowerY << whiteTowerX << std::endl;
    board[whiteTowerY][whiteTowerX] = 'T';
}
