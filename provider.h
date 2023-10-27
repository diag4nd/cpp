#ifndef PROVIDER_H
#define PROVIDER_H

class Provider
{
private:
    std::string winWord;
    std::string screenWord;
    std::string answer;
    std::string answerLog{ "" };
public:
    std::string getWinWord() const { return winWord; };
    std::string getScreenWord() const { return screenWord; };
    void setWinWord(std::string word);
    void setScreenWord();
    void setAnswer();
    std::string getAnswer() const { return answer; };
    bool isCorrectAnswer();
    bool isRightAnswer();
    bool isUsedAnswer();
    void rememberAnswer();
    bool isFinished();
    void openLetter();
};

#endif