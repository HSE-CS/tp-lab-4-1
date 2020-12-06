// Copyright 2020 Egor Buzanov
#include "../include/Automata.h"

int main() {
  Automata coffee_machine;
  coffee_machine.on();
  std::map<std::string, int> menu = coffee_machine.getMenu();
  for (const auto& item : menu) {
    std::cout << item.first << " " << item.second << std::endl;
  }
  std::cout << coffee_machine.getState() << std::endl;
  coffee_machine.coin(10);
  std::cout << coffee_machine.getState() << std::endl;
  coffee_machine.coin(10);
  coffee_machine.choice("Lemon tea");
  coffee_machine.check();
  std::cout << coffee_machine.getState() << std::endl;
  coffee_machine.cook();
  std::cout << coffee_machine.getState() << std::endl;
  coffee_machine.finish();
  std::cout << coffee_machine.getState() << std::endl;
  coffee_machine.off();
  std::cout << coffee_machine.getState() << std::endl;
  return 0;
}
