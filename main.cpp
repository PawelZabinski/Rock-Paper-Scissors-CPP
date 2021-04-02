#include <iostream>
#include "Player.h"
#include <unistd.h>
std::string getName();

int main() {
  Player main(getName());

  while ( true ) {
    main.getInput();
    sleep(5);
    printf("\033c");
  }
}

std::string getName() {
  std::string playerName;
  
  std::cout << "\u001b[35;1mWhat is Your Name > \u001b[36m";
  std::cin >> playerName;
  std::cout << "\u001b[35;1mHello, \u001b[36m" + playerName << "\u001b[35;1m!\u001b[0m" << std::endl;
  sleep(2);
  std::cout << "\033c";
  
  return playerName;
}
