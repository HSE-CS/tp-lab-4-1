// Copyright 2020 mkhorosh
#include <iostream>
#include "Automata.h"

int main() {
  Automata uniCoffee;
  std::cout << uniCoffee.getState() << std::endl;
  uniCoffee.on();
  std::cout << uniCoffee.getState() << std::endl;
  uniCoffee.coin(100);
  std::string order = "late latte lalala";
  uniCoffee.choice(order);
  std::cout << uniCoffee.getState() << std::endl;
  uniCoffee.cancel();
  uniCoffee.coin(100);
  uniCoffee.coin(10);
  std::cout << uniCoffee.getState() << std::endl;
  uniCoffee.choice(order);
  std::cout << uniCoffee.getState() << std::endl;
  uniCoffee.getMenu();
  uniCoffee.off();
  std::cout << uniCoffee.getState() << std::endl;
}
