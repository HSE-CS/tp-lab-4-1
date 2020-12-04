// Copyright AndreyBakurskii
#include "Automata.h"

int main() {
  Automata automat;

  std::cout << automat.getState() << std::endl;
  std::cout << automat.getMenu() << std::endl;

  automat.coin(20);

  return 0;
}
