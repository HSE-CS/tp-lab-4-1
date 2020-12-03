//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>
#include "Automata.h"

int main() {
  int result;
  Automata a;
  a.addCash(10);
  a.on();
  std::cout << "Current cash: " << a.getCash() << std::endl;
  a.addCash(20);
  std::cout << "Current cash: " << a.getCash() << std::endl;
  result = a.choice("Tea");
  std::cout << "Is choice (Tea) correct: " << result << std::endl;
  std::cout << "Current cash: " << a.getCash() << std::endl;
  result = a.choice("Tea");
  std::cout << "Is choice (Tea) correct: " << result << std::endl;
  a.addCash(0);
  result = a.choice("Tea");
  std::cout << "Is choice (Tea) correct: " << result << std::endl;
  a.addCash(0);
  result = a.choice("Milk");
  std::cout << "Is choice (Milk) correct: " << result << std::endl;
  a.off();
  
  Automata b;
  b.on();
  b.addCash(10);
  b.choice("Cofee");
  std::cout << "State: " << b.getState() << std::endl;
  b.cancel();
  std::cout << "State: " << b.getState() << std::endl;
}

