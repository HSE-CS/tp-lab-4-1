// Copyright 2020 Galex
#include <iostream>
#include "Automata.h"
int main() {
  Automata automata;
  std::cout << automata.getMenu();
  std::cout << (automata.getState()) << std::endl;
  automata.on();
  std::cout << (automata.getState()) << std::endl;
  automata.coin(5);
  std::cout << (automata.getState()) << std::endl;
  automata.coin(35);
  std::cout << (automata.getState()) << std::endl;
  automata.choice(1);
  std::cout << (automata.getState()) << std::endl;
  automata.off();
  std::cout << (automata.getState()) << std::endl;

}


