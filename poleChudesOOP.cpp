#include <iostream>
#include <string>

class Game
{
  private:
    int status = 0;
    
  public:
    Game() = default;
    
    void StartGame();
    void EndGame();
    int GetStatus() const;
};

class Data
{
  private:
    std::string winWord;
    std::string screenWord;
    std::string answerList;
    char answer;
    
  class Provider
  {
    public:
      Provider();
      
      void setWinWord();
      void setScreenWord();
      std::string getAnswer();
      bool isCorrectAnswer();
      bool isRightAnswer();
      bool isUsedAnswer();
      void addAnswer();
      void openLetter();
  };
  Provider prov();  
};
    
int main()
{
    Game poleChudes;
    poleChudes.StartGame();
    
    poleChudes.EndGame();
    return 0;
}

void Game::StartGame()
{
  status = 1;
  std::cout << "Game started. Status:" << status << std::endl;
}

void Game::EndGame()
{
  status = 2;
  std::cout << "Game ended. Status:" << status << std::endl;
}

int Game::GetStatus() const
{
  return status;
}

void Provider::setWinWord()
{
  winWord = "Рапорт";
}

void Provider::setScreenWord()
{
  for (int i=0; i<winWord.length(); i++)
  {
    screenWord.append('-');
  }
}

std::string Provider::getAnswer()
{
  char word[256];
  std::cout << "Назовите букву: ";
  std::cin.getline(word, 256, '\n');
}

bool Provider::isCorrectAnswer()
{
  if (answer.length() != 1)
  {
    return false;
  }
  else if (not ((answer[0] >= 'a') and (answer[0] <= 'z') or ((answer[0] >= 'A') and (answer[0] <= 'Z')) or ((answer[0] >= 'а') and (answer[0] <= 'я')) or ((answer[0] >= 'А') and (answer[0] <= 'Я'))) )
    {
      return false;
    }
  return true;
}

bool Provider::isRightAnswer()
{
  for (int i=0; i<winWord.length(); i++)
  {
    if ( (winWord[i] == answer) and (screenWord[i] == '-') )
    {
      return true;
    }
  }
  return false;
}

bool Data::Provider::isUsedAnswer()
{
  for (int i=0; i<answerList.length(); i++)
  {
    if (answerList[i] == answer)
    {
      return true;
    }
  }
  return false;
}

void Provider::addAnswer()
{
  answerList.append(answer);
}

void Provider::openLetter()
{
  for (int i=0; i<winWord.length(); i++)
  {
    if (winWord[i] == answer)
    {
      screenWord[i] = answer;
    }
  }
}