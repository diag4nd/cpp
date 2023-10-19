#include <iostream>
#include <string>
#include <windows.h>

class Game
{
  private:
    int status;
    std::string power;
    
  public:
    Game(): status{0}, power{'+'}
    {}
    void startGame() {status = 1;};
    void checkGame() {status = 2;};
    void endGame() {status = 3;};
    int getStatus() const {return status;};
    void setPower();
    bool isCorrectPower();
    char getPower() const {return power[0];};
};

class Provider
{
  private:
    std::string winWord;
    std::string screenWord;
    std::string answer;
  public:
    std::string getWinWord() const {return winWord;};
    std::string getScreenWord() const {return screenWord;};
    void setWinWord(std::string word);
    void setScreenWord();
    void setAnswer();
    std::string getAnswer() const {return answer;};
    bool isCorrectAnswer();
    bool isRightAnswer();
    bool isFinished();
    void openLetter();
};
   
class Screen
{
  public:
    void askNewGame();
    void askAnswer();
    void showWord(std::string word);
    void showError();
    void showCorrect();
    void showIncorrect();
    void showWin();
    void showStart();
    void showEnd();
};  

int main()
{
    SetConsoleCP(1251);
	  SetConsoleOutputCP(1251);
    
    Game poleChudes;
    Provider jacub;
    Screen screen;
    
    screen.askNewGame();
    poleChudes.setPower();
    while (not poleChudes.isCorrectPower())
    {
      screen.showError();
      screen.askNewGame();
      poleChudes.setPower();
    }
    while (poleChudes.getPower() != '-')
    {
      poleChudes.startGame();
      screen.showStart();
    
      jacub.setWinWord("Doorbell");
      jacub.setScreenWord();
    
      screen.showWord( jacub.getScreenWord() );
      while (poleChudes.getStatus() != 2)
      {
        screen.askAnswer();
        jacub.setAnswer();
        while (not jacub.isCorrectAnswer())
        {
          screen.showError();
          screen.askAnswer();
          jacub.setAnswer();
        }
        if(jacub.isRightAnswer())
        {
          screen.showCorrect();
          jacub.openLetter();
        }
        else
        {
          screen.showIncorrect();
        }
      
        screen.showWord( jacub.getScreenWord() );
        if(jacub.isFinished())
        {
          poleChudes.checkGame();
        }
      }
      screen.showWin();
      poleChudes.endGame();
      screen.showEnd();
      
      screen.askNewGame();
      poleChudes.setPower();
    }
 
    return 0;
}

void Game::setPower()
{
  std::string ans;
  std::getline(std::cin, ans);
  power = ans;
}

bool Game::isCorrectPower()
{
  if (power.length() != 1)
  {
    return false;
  }
  else if ( not (( power[0] == '+' ) or (power[0] == '-')) )
  {
    return false;
  }
  return true;
}

void Provider::setWinWord(std::string word)
{
  winWord = word;
}

void Provider::setScreenWord()
{
  std::string line(winWord.length(), '_');
  screenWord = line;
}

void Provider::setAnswer()
{
  std::string ans;
  std::getline(std::cin, ans);
  answer = ans;
}

bool Provider::isCorrectAnswer()
{
  if (answer.length() != 1)
  {
    return false;
  }
  else if ( not ( ((answer[0] >= 'a') and (answer[0] <= 'z')) or ((answer[0] >= 'A') and (answer[0] <= 'Z')) or ((answer[0] >= 'а') and (answer[0] <= 'я')) or ((answer[0] >= 'А') and (answer[0] <= 'Я'))) )
  {
    return false;
  }
  return true;
}

bool Provider::isRightAnswer()
{
  for(int i=0; i<winWord.length(); i++)
  {
    if( (answer[0] == winWord[i]) and (screenWord[i] == '_') )
    {
      return true;
    }
  }
  return false;
}

bool Provider::isFinished()
{
  for(int i=0; i<winWord.length(); i++)
  {
    if( screenWord[i] == '_' )
    {
      return false;
    }
  }
  return true;
}

void Provider::openLetter()
{
  for(int i=0; i<winWord.length(); i++)
  {
    if(winWord[i] == answer[0])
    {
      screenWord[i] = answer[0];
    }
  }
}

void Screen::askNewGame()
{
  std::cout << "Хотите начать новую игру?\n('+' - да, '-' - нет)\nВведите ответ: ";
}

void Screen::askAnswer()
{
  std::cout << "Назовите букву: ";
}

void Screen::showWord(std::string word)
{
  std::cout << word << std::endl;
}

void Screen::showError()
{
  std::cout << "Некорректный ввод!" << std::endl;
}

void Screen::showCorrect()
{
  std::cout << "Откройте!" << std::endl << std::endl;
}

void Screen::showIncorrect()
{
  std::cout << "Нет такой буквы!" << std::endl << std::endl;
}

void Screen::showWin()
{
  std::cout << "Вы победили!" << std::endl;
}

void Screen::showStart()
{
  std::cout << "Игра началась!" << std::endl << std::endl;
}

void Screen::showEnd()
{
  std::cout << "Игра закончилась!" << std::endl << std::endl;
}
