#include<iostream>
long long factorial(long long x)
{
  if (x==1)
  {
    return 1;
  }
  return x*factorial(x-1);
}
 
std::string getAnswer()
{
  std::cout << "Введите одно натуральное число: ";
  std::string word;
  std::getline(std::cin,  word);
  return word;
}

bool isString(std::string word)
{
  for (int i=0; i<word.length(); i++)
  {
    if (not isdigit(word[i]))
    {
      return true;
    }
  }
  return false;
}

bool isNegative(std::string word)
{
  if (word[0] == '-')
  {
    for (int i=1; i<word.length(); i++)
    {
      if (not isdigit(word[i]))
      {
        return false;
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}

bool isFloat(std::string word)
{
  int dotNum = 0;
  if (isdigit(word[0]))
  {
    for (int i = 1; i<word.length(); i++)
    {
      if (not isdigit(word[i]))
      {
        if ( (word[i] == '.') and (dotNum == 0) )
        {
          dotNum++;
        }
        else
        {
          return false;
        }
      }
    }
    if (dotNum == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool isBig(unsigned long long num)
{
  if (num > 20)
  {
    return true;
  }
  return false;
}

bool isAcceptable(std::string ans)
{
  if (isNegative(ans))
    {
      std::cout << "Отрицательное число" << std::endl;
      return false;
    }
  else if (isFloat(ans))
    {
      std::cout << "Нецелое число" << std::endl;
      return false;
    }
  else if (not isString(ans))
    {
      unsigned long long ansInt, fact;
      ansInt = std::stoi(ans);
      
      if (isBig(ansInt))
      {
        std::cout << "Слишком большое" << std::endl;
        return false;
      }
      fact = factorial(ansInt);
      std::cout << ans + "! = " << fact << std::endl;
      return true;
    }
  else
    {
      std::cout << "Недопустимый формат" << std::endl;
      return false;
    }
}


int main()
{
    std::string ans;
    ans = getAnswer();
    
    while (not isAcceptable(ans))
    {
      ans = getAnswer();
    }
    
    return 0;
}