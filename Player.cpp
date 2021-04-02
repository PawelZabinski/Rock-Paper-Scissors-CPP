#include <iostream>
#include <unistd.h>
#include <ctime>
#include "Player.h"

// Rock Paper Scissors Options //
enum RockPaperScissors
{
  Rock = 0, Paper, Scissors
};

// Constructor //
Player::Player(const std::string& a)
  : name(a) 
{}

// Get Input From Player //
void Player::getInput()
{
  try
  {
    std::string verifyUserChoice;
    std::cout << "\u001b[35;1mLet's Play Rock Paper Scissors!\u001b[0m" << std::endl;
    std::cout << "\u001b[36;1m[Rock - 0; Paper - 1; Scissors - 2]" << std::endl;
    std::cout << "ENTER YOUR CHOICE > ";
    std::cin >> verifyUserChoice;
    std::cout << "\u001b[0m";
    this -> userChoice = std::stoi(verifyUserChoice);

    if (this -> userChoice >= 3)
      throw 404;

    usleep(1000);
    printf("\033c");

  } catch (...)
  {
    std::cout << "\u001b[31m[INVALID OPTION]\u001b[31m - Please Select Rock, Paper, or Scissors.\u001b[0m" << std::endl;
    return;
  }

  // CountDown //
  std::cout << "\u001b[36;1mRock!\u001b[0m" << std::endl;
  sleep(1);
  std::cout << "\u001b[34;1mPaper!\u001b[0m" << std::endl;
  sleep(1);
  std::cout << "\u001b[35;1mScissors!\u001b[0m" << std::endl;
  sleep(1);
  std::cout << "\u001b[36;1mShoot!\u001b[0m" << std::endl;
  sleep(1);
  
  // Clear The Screen //
  printf("\033c");
  
  // Check The Results Of The Game. //
  this -> checkGameResult(this -> userChoice);
}

// Check The Results Of The Game //
void Player::checkGameResult(int a)
{
  srand(time(NULL));
  int computerAnswer = rand() % 3;

  // Display User Choice //
  std::cout << "You Have Chosen ";

  if (a == 0)
    std::cout << "\u001b[36;1mRock!\u001b[0m" << std::endl;
  else if (a == 1)
    std::cout << "\u001b[34;1mPaper!\u001b[0m" << std::endl;
  else if (a == 2)
    std::cout << "\u001b[35;1mScissors!\u001b[0m" << std::endl;

  sleep(1);

  // Display Computer Choice //

  std::cout << "The Computer Has Chosen ";

  if (computerAnswer == 0)
    std::cout << "\u001b[36;1mRock!\u001b[0m" << std::endl;
  else if (computerAnswer == 1)
    std::cout << "\u001b[34;1mPaper!\u001b[0m" << std::endl;
  else if (computerAnswer == 2)
    std::cout << "\u001b[35;1mScissors!\u001b[0m" << std::endl;


  sleep(1);
  std::cout << std::endl;

  // Check Game Results //

  switch (a)
  {
    case RockPaperScissors::Rock:
    // If User Picks Rock //
      switch (computerAnswer)
      {
        case RockPaperScissors::Rock:
          this -> userDraws();
          break;
        case RockPaperScissors::Paper:
          this -> userLooses();
          break;
        case RockPaperScissors::Scissors:
          this -> userWins();
          break;
      }
      break;
    case RockPaperScissors::Paper:
    // If User Picks Paper //
      switch (computerAnswer)
      {
        case RockPaperScissors::Paper:
          this -> userDraws();
          break;
        case RockPaperScissors::Scissors:
          this -> userLooses();
          break;
        case RockPaperScissors::Rock:
          this -> userWins();
          break;
      }
      break;
    case RockPaperScissors::Scissors:
    // If User Picks Scissors //
      switch (computerAnswer)
      {
        case RockPaperScissors::Scissors:
          this -> userDraws();
          break;
        case RockPaperScissors::Rock:
          this -> userLooses();
          break;
        case RockPaperScissors::Paper:
          this -> userWins();
          break;
      }
      break;
  }
}

// Functions Gets Called When The Game Results in a Tie //
void Player::userDraws()
{
  std::cout << "The Game Resulted in a \u001b[33;1m[Tie]\u001b[0m" << std::endl;
  std::cout << "You Currently Have " << this -> wins << " Wins, and " << this -> losses << " Losses!" << std::endl;
}

// Function Gets Called When Player Wins
void Player::userWins()
{
  this -> wins++;
  std::cout <<"\u001b[32;1m[" << this -> name << "]\u001b[0m Wins The Game!" << std::endl;
  std::cout << "You Currently Have " << this -> wins << " Wins, and " << this -> losses << " Losses; Keep it Up!" << std::endl;
}

// Function Gets Called When Player Looses //
void Player::userLooses() 
{
  this -> losses++;
  std::cout << "\u001b[31;1m[The Computer]\u001b[0m Has Won The Game!" << std::endl;
  std::cout << "You Currently Have " << this -> wins << " Wins, and " << this -> losses << " Losses! Better Luck Next Time!" << std::endl;
}
