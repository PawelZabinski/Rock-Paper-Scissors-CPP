#pragma once

class Player
{
  private:
    unsigned int wins = 0;
    unsigned int losses = 0;
    int userChoice;
    const std::string name;
  public:
    Player(const std::string& a);
    void getInput();
    void checkGameResult(int a);


    void userWins();
    void userDraws();
    void userLooses();
};
